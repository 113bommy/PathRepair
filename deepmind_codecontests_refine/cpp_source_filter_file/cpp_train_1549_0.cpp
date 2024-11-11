#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;
typedef long long int ll;

int n,k;
vector<int> G[2100];

int dfs(int t,int f,int k,int depth=0){
	int cnt=0;
	if(depth>=k)cnt++;
	for(auto d:G[t]){
		if(d==f)continue;
		cnt+=dfs(d,t,k,depth+1);
	}
	return cnt;
}

int main(){
	cin >> n >> k;
	for(int i=0;i<n-1;i++){
		int a,b; cin >> a >> b;
		a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	int ans=n;
	for(int i=0;i<n;i++){
		int cnt=0;
		for(int t:G[i]){
			cnt+=dfs(t,i,k/2);
		}
		ans=min(ans,cnt);
	}
	for(int i=0;i<n;i++){
		for(int t:G[i]){
			int cnt=dfs(t,i,(k+1)/2)+dfs(t,s,(k+1)/2);
			ans=min(ans,cnt);
		}
	}
	cout << ans << endl;
}