#include<bits/stdc++.h>
using namespace std;
int len[10010];
int res[10010];
int dp[10010];
int n,m;
int x;
bool yes[10010];
int cost[10]={1e9,2,5,5,4,5,6,3,7,6};
int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>x;
		yes[x]=true;
	}
	memset(res,-1,sizeof(res));
	res[0]=0;
	for(int i=1;i<=n;i++){
		for(int j=9;j>=1;j--){
			if(cost[j]<=i&&yes[j]&&res[i-cost[j]]!=-1){
				if(len[i]<len[i-cost[j]]+1){
					len[i]=len[i-cost[j]]+1;
					res[i]=j;
					dp[i]=i-cost[j];
				}
			}
		}
	}
	for(int i=n;i;i=dp[i])
		cout<<res[i]; 
	return 0;
}
