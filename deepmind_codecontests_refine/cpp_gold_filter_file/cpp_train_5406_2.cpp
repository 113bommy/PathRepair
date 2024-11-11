#include <bits/stdc++.h>
using namespace std;
using vi=vector<int>;
using vvi=vector<vi>;
#define rep(i,n) for(int i=0;i<n;i++)
#define all(a) a.begin(),a.end()

vvi matmul(vvi a, vvi b){
	int n=a.size();
	vvi d(n,vi(n,0));
	rep(i,n)rep(j,n)rep(k,n) d[i][j]|=a[i][k]&b[k][j];
	return d;
}

unordered_map<int,vvi> memo;
inline vvi matpow(vvi a,int p){
	return memo[p]=memo.find(p)==memo.end()?p%2?matmul(matpow(a,p-1),a):matmul(matpow(a,p/2),matpow(a,p/2)):memo[p];
}

int main(){
	int n,m,a[3];
	while(cin>>n>>m>>a[0]>>a[1]>>a[2]){
		vvi z(n,vi(n,0)), e=z;
		rep(_,m){
			int p,q; cin>>p>>q;
			e[p-1][q-1]=1;
		}
		memo.clear();
		memo[1]=e;

		vector<vvi> d(3);
		rep(p,3) d[p]=matpow(e,a[p]);
		
		vi g(n,0), ng(n,0);
		g[n-1]=1;
		rep(t,1000){
			bool next=0;
			fill(all(ng),0);
			rep(i,n) if(!g[i]){
				bool ok=1,r;
				rep(p,3) [&]{r=0; rep(j,n) r|=(g[j] and d[p][i][j]); ok&=r;}();
				if(ok) ng[i]=next=1;
			}
			if(!next){
				cout<<"IMPOSSIBLE"<<endl;
				break;
			} else if(ng[0]){
				cout<<t+1<<endl;
				break;
			}
			rep(i,n)g[i]|=ng[i];
		}
	}
	return 0;
}

