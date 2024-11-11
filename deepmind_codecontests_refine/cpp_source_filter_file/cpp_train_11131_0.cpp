#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cstdio>
using namespace std;
map<set<int>,int>memo;

int M,N;
vector<string>v;
int dfs(set<int> &t){
	if(t.size()==1)return 0;
	if(memo.find(t)!=memo.end())return memo[t];
	int r=1<<30;
	for(int j=0;j<M;j++){
		set<int>a,b;
		for(auto &e:t)(v[e][j]=='0'?a:b).push_back(e);
		if(a.size()&&b.size())r=min(r,max(dfs(a),dfs(b))+1);
	}
	return memo[t]=r;
}

int main(){
	for(;cin>>M>>N,M;){
		v.resize(N);
		for(int i=0;i<N;i++)cin>>v[i];
		set<int>t;
		for(int i=0;i<N;i++)t.insert(i);
		memo.clear();
		printf("%d\n",dfs(t));
	}
}