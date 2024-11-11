#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<n;i++)
#define all(a) a.begin(),a.end()
#define INF 1e9

using vi=vector<int>;
using vvi=vector<vi>;

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
		rep(l,*max_element(a,a+3)){
			rep(p,3) if(l==a[p]-1) d[p]=f;
			auto next=z;
			rep(k,n)rep(i,n)rep(j,n){
				next[i][j]|=(f[i][k] and e[k][j]);
			}
			f=next;
		}
		
		unordered_set<int> g;
		g.insert(n-1);
		rep(t,1000){
			unordered_set<int> ng;
			rep(i,n) if(!g.count(i)){
				bool ok=1;
				rep(p,3) [&]{bool r=0; rep(j,n) r|=(g.count(j) and d[p][i][j]); ok&=r;}(ok);
				if(ok) ng.insert(i);
			}
			if(ng.size()==0){
				cout<<"IMPOSSIBLE"<<endl;
				break;
			} else if(ng.count(0)){
				cout<<t+1<<endl;
				break;
			}
			g.insert(all(ng));
		}
	}
	return 0;
}

