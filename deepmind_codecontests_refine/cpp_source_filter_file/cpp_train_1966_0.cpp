#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <complex>
#include <map>
#include <climits>
#include <sstream>
using namespace std;

#define reep(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n) reep((i),0,(n))
#define ALL(v) (v).begin(),(v).end()
#define PB push_back
#define EPS 1e-8
#define F first
#define S second
#define mkp make_pair

static const double PI=6*asin(0.5);
typedef long long ll;
typedef complex<double> CP;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vint;
static const int INF=1<<24;

template <class T>
void initvv(vector<vector<T> > &v,int a,int b, const T  &t = T()){
	v.assign(a,vector<T>(b,t));
}

//v.erase(unique(v.begin(),v.end()),v.end());

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
int main(){
	int n;
	cin>>n;
	rep(l,n){
		if(i) cout<<endl;
		int m;
		cin>>m;
		// cout<<m<<endl;
		if(m==1){
			cout<<"#\n";
			continue;
		}
		if(m==2){
			cout<<"##\n";
			cout<<"# \n";
			continue;
		}
		if(m==3){
			/*
			###
			# #
			# #
			*/
			cout<<"###\n";
			cout<<"# #\n";
			cout<<"# #\n";
			// cout<<"\n";
			continue;
		}
		if(m==4){
			cout<<"####\n";
			cout<<"#  #\n";
			cout<<"#  #\n";
			cout<<"# ##\n";
			// cout<<endl;
			continue;
		}
		vector<vector<char> > vv;
		initvv(vv,m,m);
		rep(i,m){
			rep(j,m) vv[i][j]=' ';
		}
		rep(i,m){
			vv[0][i]='#';
			vv[m-1][i]='#';
			vv[i][m-1]='#';
			vv[i][0]='#';
		}
		vv[m-1][1]=' ';
		int x=m-1,y=2;
		int c=0;
		while(1){
			// cout<<x<<" "<<y<<endl;
			if(vv[x+dx[c]*2][y+dy[c]*2]==' '){
				x+=dx[c];
				y+=dy[c];
				vv[x][y]='#';
			}
			else if(vv[x+2*dx[(c+1)%4]][y+2*dy[(c+1)%4]]==' '&&vv[x+dx[(c+1)%4+dx[(c+2)%4]]][y+dy[(c+1)%4]+dy[(c+2)%4]]==' '){
				c++;
				c%=4;
				x+=dx[c];
				y+=dy[c];
				vv[x][y]='#';
			}
			else{
				break;
			}
		}
		/*
		######
		#    #
		# ## #
		# #  #
		# #  #
		# ####
		*/
		rep(i,m){
			rep(j,m){
				cout<<vv[i][j];
			}
			cout<<endl;
		}
		cout<<endl;
	}
}