#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<set>
#include<list>
#include<queue>
#include<cmath>
#include<functional>
#include<algorithm>
#define INF (1<<29)
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;


struct Range{
	int s,e;
	Range(){}
	Range(int s,int e):s(s),e(e){}
	bool operator<(const Range &r)const{return e<r.e;}
};
vector<Range> merge_range(vector<Range> r){
	vector<Range> res;
	sort(r.begin(),r.end());
	for(int i=0;i<(int)r.size();i++){
		int mi=r[i].s;
		while(!res.empty()&&r[i].s<=res.back().e){
			mi=min(mi,res.back().s);
			res.pop_back();
		}
		res.push_back(Range(mi,r[i].e));
	}
	return res;
}


int main(){
	int n,m;
	Range r[500];
	cin>>n>>m;
	rep(i,m)cin>>r[i].s>>r[i].e;
	int ans=n+1;
	vector<Range> vr(merge_range(vector<Range>(r,r+m)));
	rep(i,vr.size()){
		ans+=(vr[i].e-vr[i].s)*2;
	}
	cout<<ans<<endl;
	return 0;
}