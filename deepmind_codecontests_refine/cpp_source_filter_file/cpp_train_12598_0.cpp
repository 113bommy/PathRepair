#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

class Vector
{
public:
	double x,y;
	Vector (double x=0,double y=0):x(x),y(y){}
	
	Vector operator + (Vector p){return Vector(x+p.x,y+p.y);}
	Vector operator - (Vector p){return Vector(x-p.x,y-p.y);}
	Vector operator * (double a){return Vector(x*a,y*a);}
	Vector operator / (double a){return Vector(x/a,y/a);}
	
	double abs() {return sqrt(norm());}
	double norm(){return x*x+y*y;}
};

double cross(Vector a,Vector b)
{
	return abs(a.x*b.y-b.x*a.y);
}

int main()
{
	int n;cin>>n;
	Vector p0,p1,p2,p3;
	cout<<fixed<<setprecision(10);
	for(int i=0;i<n;i++)
	{
		cin>>p0.x>>p0.y>>p1.x>>p1.y>>p2.x>>p2.y>>p3.x>>p3.y;
		Vector base=p3-p2;
		Vector hypo1=p0-p2;
		Vector hypo2=p1-p3;
		
		double d1=cross(base,hypo1);
		double d2=cross(base,hypo2);
		
		double t=d1/(d1+d2);
		Vector x=p0+(p1-p0)*t;
		cout<<x.x<<" "<x.y<<endl;
	}
	return 0;
}