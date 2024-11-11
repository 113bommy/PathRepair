#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define repr(i,n) for(int i=(n)-1;i>=0;i++)
#define repf(i,j,n) for(int i=(j);i<(n);i++)

struct rw{
	int t,x,e;
	rw(){};
	rw(int t_,int x_,int e_){
		t=t_,x=x_,e=e_;
	};
	bool operator<(const rw& o)const {return t<0.t;}
};

signed main(){
	int n,q;cin>>n>>q;
	vector<int> d(q),ans;
	vector<rw> r;
	rep(i,n){
		int s,t,x;cin>>s>>t>>x;
		r.push_back(rw(s-x,x,1));
		r.push_back(rw(t-x,x,-1);} 
	for(auto&& u:d)cin>>u;
	sort(begin(r),end(r));

		int idx=0;
		multiset<int>s; 
	for(auto&& u:d){
		while(idx<r.size()&&u<=r[idx].t){
			if(r[idx].e==1)s.insert(r[idx].x);
			else s.erase(s.find(r[idx].x));
			idx++;
		}
		if(s.empty())ans.push_back(-1);
		else ans.push_back(*begin(s));
	}	
	for(auto&& u:ans)cout<<u<<endl;
}
