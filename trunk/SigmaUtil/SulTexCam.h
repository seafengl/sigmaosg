// SulTexCam.h

#ifndef __SULTEXCAM_H__
#define __SULTEXCAM_H__

#include "SulTypes.h"
#include "SulExport.h"
#include <osg/camera>
#include <osg/texture2d>

class SUL_EXPORT CSulTexCam : public osg::Camera
{
public:
	enum ESETUP
	{
		STANDARD,
		SHADOW,
		HDR
	};

public:
						CSulTexCam( Sigma::uint32 w, Sigma::uint32 h, ESETUP eSetup=STANDARD );
						CSulTexCam( osg::Texture2D* pTex, ESETUP eSetup=STANDARD );

	void				setTexture( osg::Texture2D* pTex );
	osg::Texture2D*		getTexture();

private:
	void				initTex();
	void				initCam();

private:
	osg::ref_ptr<osg::Texture2D>	m_rTex;
	Sigma::uint32					m_w;
	Sigma::uint32					m_h;
	ESETUP							m_eSetup;
};

#endif // __SULTEXCAM_H__