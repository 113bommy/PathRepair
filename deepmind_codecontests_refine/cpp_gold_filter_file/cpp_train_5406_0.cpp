#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<n;i++)
#define all(a) a.begin(),a.end()
#define INF 1e9

using vi=vector<int>;
using vvi=vector<vi>;

vvi matmul(vvi a, vvi b){
	int n=a.size();
	auto d=vvi(n,vi(n,0));
	rep(i,n)rep(j,n)rep(k,n){
		d[i][j]|=a[i][k]*b[k][j];
	}
	return d;
}

vvi matpow(vvi a,int p){
	static map<int,vvi> memo;
	memo[1]=a;
	if(memo.find(p)==memo.end()){
		if(p%2){
			memo[p]=matmul(matpow(a,p-1),a);
		}else{
			auto r=matpow(a,p/2);
			memo[p]=matmul(r,r);		
		}
	}
	return memo[p];
}

int main(){
	int n,m,a[3];
	while(cin>>n>>m>>a[0]>>a[1]>>a[2]){
		vvi z(n,vi(n,0));
		auto e=z;
		rep(_,m){
			int p,q; cin>>p>>q;
			e[p-1][q-1]=1;
		}

		vector<vvi> d(3);
		auto f=e;
		rep(p,3){
			d[p]=matpow(e,a[p]);
		}
		
		vi g(n,0);
		g[n-1]=1;
		rep(t,1000){
			bool next=0;
			vi ng(n,0);
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

