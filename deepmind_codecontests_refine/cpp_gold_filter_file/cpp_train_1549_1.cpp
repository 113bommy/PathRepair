#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<queue>
#include<deque>
#include<stack>
using namespace std;

int n,l,ans;
vector<int> nei[2005];

int dfs(int x,int p,int d,int mx){
	int res=1;
	if(d!=mx) for(int i=0;i<nei[x].size();i++) if(nei[x][i]!=p) res+=dfs(nei[x][i],x,d+1,mx);
	return res;
}

int main(){
	cin>>n>>l;
	for(int i=0;i<n-1;i++){
		int x,y;
		cin>>x>>y;
		nei[x].push_back(y);
		nei[y].push_back(x);
	}
	if(l%2==0) for(int i=1;i<=n;i++) ans=max(ans,dfs(i,-1,0,l/2));
	else for(int i=1;i<=n;i++) for(int j=0;j<nei[i].size();j++) ans=max(ans,dfs(i,nei[i][j],0,l/2)+dfs(nei[i][j],i,0,l/2));
	cout<<n-ans<<endl;
	return 0;
}