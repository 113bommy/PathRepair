#include<iostream>
#include<math>

#define conv 0.0174532925199

using namespace std;

int main()
{
	double x=0.0,y=0.0,m,r,rad=0;
	char a;
	
	for(;;)
	{
		cin >> m >> a >> r ;
		if(m==0 && r==0)
			break;
		x+=m*sin(rad*conv);
		y+=m*cos(rad*conv);
		rad+=r;
	}
	cout << (int)x << endl;
	cout << (int)y << endl;
}