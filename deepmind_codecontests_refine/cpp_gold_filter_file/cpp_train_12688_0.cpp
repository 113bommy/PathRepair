#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>
#include <set>
#include <cstdio>
#include <cmath>
#define rep(i,l,n) for(lint i=l;i<n;i++)
#define rer(i,l,n) for(lint i=l;i<=n;i++)
#define all(a) a.begin(),a.end()
#define o(a) cout<<a<<endl
#define pb(a) push_back(a)
#define mk(a,b) make_pair(a,b)
#define fi first
#define se second
using namespace std;
typedef long long lint;
typedef vector<int> vi;
typedef vector<lint> vli;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

//double M_PI=acos(-1);

int main(){
	double a[2],b[2],r=6378.1;
	while(1){
		rep(i,0,2) cin>>a[i]>>b[i];
		if(a[0]==-1 && b[0]==-1 && a[1]==-1 && b[1]==-1) break;
		double x[2],y[2],z[2],d2,l,c=M_PI/180.0;
		/*rep(i,0,2) x[i]=r*cos(a[i]*c)*cos(b[i]*c);
		rep(i,0,2) y[i]=r*sin(a[i]*c)*cos(b[i]*c);
		rep(i,0,2) z[i]=r*sin(b[i]*c);
		d2=(x[1]-x[0])*(x[1]-x[0])+(y[1]-y[0])*(y[1]-y[0])+(z[1]-z[0])*(z[1]-z[0]);
		o(" "<<d2);
		double t=acos(1-d2/(2.0*r*r));
		o(t);
		l=r*t;
		l=int(l+0.5);
		o(l);*/
		double t=acos(cos(a[0]*c)*cos(a[1]*c)*cos(b[0]*c-b[1]*c)+sin(a[0]*c)*sin(a[1]*c));
		double ans=r*t;
		ans=(int)(ans+0.5);
		o(ans);
	}
}