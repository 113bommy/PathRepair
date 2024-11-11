#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<string>

using namespace std;

#define rep(i,n) for(int i=0;i<int(n);i++)
#define reps(i,n) for(int i=1;i<=int(n);i++)
#define sint(i) scanf("%d",&i);
#define sintt(i,j) scanf("%d%d",&i,&j);
#define sinttt(i,j,k) scanf("%d%d%d",&i,&j,&k);
#define sintttt(i,j,k,m) scanf("%d%d%d%d",&i,&j,&k,&m);

#define INF 1010000000
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

short dp[4001][4001];

int main(){
	while(1){
		string a,b;
		cin>>a>>b;
		
		if(b.size()==0){
			break;
		}
		
		rep(i,4001)rep(j,4001)dp[i][j]=0;
		
		short maxi=0;
		reps(i,a.size()){
			reps(j,b.size()){
				if(a[i-1]==b[j-1]){
					dp[i][j]=dp[i-1][j-1]+1;
				}
				maxi=max(maxi,dp[i][j]);
			}
		}
		
		printf("%d\n",maxi);
	}
}