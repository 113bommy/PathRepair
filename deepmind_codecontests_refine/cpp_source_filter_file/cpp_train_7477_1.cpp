#include <bits/stdc++.h>
#define syosu(x) fixed<<setprecision(x)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef pair<double,double> pdd;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<string> vs;
typedef vector<P> vp;
typedef vector<vp> vvp;
typedef vector<pll> vpll;
typedef pair<P,int> pip;
typedef vector<pip> vip;
const int inf=1<<30;
const ll INF=1ll<<60;
const double pi=acos(-1);
const double eps=1e-8;
const ll mod=1e9+7;
const int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};

int h,w;
vs a;

int main(){
	cin>>h>>w;
	a=vs(h);
	for(int i=0;i<h;i++) cin>>a[i];
	vi b(h);
	for(int i=0;i<h;i++) b[i]=i/2;
	do{
		int tmp=0;
		bool B=1;
		for(int i=0;i<h;i++){
			if(tmp==b[i]) tmp++;
			else if(tmp<b[i]&&b[i]<n/2) B=0;
		}
		if(!B) continue;
		vi c(h);
		vs A(h);
		for(int i=0;i<h;i++){
			if(c[b[i]]) A[h-b[i]-1]=a[i];
			else c[b[i]]=1,A[b[i]]=a[i];
		}
		c=vi(w);
		for(int i=0;i<w;i++) if(!c[i]){
			string s;
			for(int j=0;j<h;j++) s+=A[j][i];
			for(int j=i+1;j<w;j++) if(!c[j]){
				string t;
				for(int k=0;k<h;k++) t+=A[k][j];
				reverse(t.begin(),t.end());
				if(s==t){
					c[i]=1;c[j]=1;
					break;
				}
			}
			if(!c[i]&&w%2==1&&B){
				string s_=s;
				reverse(s.begin(),s.end());
				if(s==s_) c[i]=1,B=0;
			}
		}
		B=1;
		for(int i=0;i<w;i++) if(!c[i]) B=0;
		if(B){
			cout<<"YES"<<endl;
			return 0;
		}
	}while(next_permutation(b.begin(),b.end()));
	cout<<"NO"<<endl;
}