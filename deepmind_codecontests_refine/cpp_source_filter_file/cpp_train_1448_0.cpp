#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<utility>
#include<cmath>
#include<cstring>
#include<queue>
#include<cstdio>
#include<sstream>
#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)
#define pb push_back
#define mp make_pair
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)
const double PI=acos(-1);
const double EPS=1e-8;
const int inf=1e9;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
vvi in;
int main(){
	int n,m,r;
	while(cin>>n>>m>>r,n){
		vi x(n),y(n);
		rep(i,n)cin>>x[i]>>y[i];
		in=vvi(10010);
		rep(i,m){
			int a,b;
			cin>>a>>b;
			in[a].pb(b);
		}
		rep(i,10010)sort(all(in[i]));
		int out=0;
		rep(i,n){
			loop(j,max(0,x[i]-4*r),min(x[i]+4*r,10010)){
				int s=lower_bound(all(in[j]),y[i]-4*r)-in[j].begin();
				int t=upper_bound(all(in[j]),y[i]+4*r)-in[j].begin();
				loop(k,s,t)if((j-x[i])*(j-x[i])+(y[i]-in[j][k])*(y[i]-in[j][k])<=16*r*r)out++;
			}
		}
		cout<<out<<endl;
	}
}
 