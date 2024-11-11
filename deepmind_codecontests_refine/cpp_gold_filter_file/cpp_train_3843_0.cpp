#include<cstdio>
#include<iostream>
#include<vector>
#include<complex>
#include<algorithm>
#include<cmath>

using namespace std;

#define reps(i,f,n) for(int i=f;i<int(n);i++)
#define rep(i,n) reps(i,0,n)

typedef complex<double> Point;

const double EPS = 0.000001;

int main(){
	
	A:;
	
	int n;
	cin>>n;
	
	if(n==0)return 0;
	
	vector<Point> point;
	rep(i,n){
		double a,b;
		cin>>a>>b;
		point.push_back(Point(a,b));
	}
	
	int ans = 1;
	rep(i,n){
		rep(j,n){
			if(i==j)continue;
			
			Point p1 = point[j];
			Point p0 = point[i];
			
			Point diff = p1-p0;
			Point d2 = diff/Point(2,0);
			
			double dlen = abs(d2);
			if(dlen>1.0)continue;
			
			double clen = sqrt(1-dlen*dlen);
			Point e = d2*Point(0,1);
			e = e/Point(abs(e),0)*Point(clen,0);
			
			Point t = p0 + d2 + e;
			
			int count = 0;
			rep(k,n){
				if(abs(t-point[k])<=1.0+EPS)count++;
			}
			ans = max(ans,count);
		}
	}
	
	printf("%d\n",ans);
	
	goto A;
}
/*
3
6.47634 7.69628
5.16828 4.79915
6.69533 6.20378

2
0 0
0.8 0

2
0 0
0.5 0.5

2
0 0
0 2

6
7.15296 4.08328
6.50827 2.69466
5.91219 3.86661
5.29853 4.16097
6.10838 3.46039
6.34060 2.41599

*/