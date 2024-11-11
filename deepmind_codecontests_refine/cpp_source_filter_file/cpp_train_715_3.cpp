#include <bits/stdc++.h>
#define R(i,n) for(int i=0;i<n;i++)
using namespace std;
main(){
int N,M,i,j;
cin>>N>>M;
vector<int>D(N);
vector<int>C(M);
R(i,N){cin>>D[i];}
R(i,M){cin>>C[i];}
vector<vector<int> >dp(M+1,vector<int>(N+1,1<<30));dp[0][0]=0;
R(i,M){R(0,N+1){
if(j==0){dp[i+1][j]=dp[i][j];}
else{dp[i+1][j]=min(dp[i][j],dp[i][j-1]+C[i]*D[j-1]);}}}
cout<<dp[M][N]<<endl;
return 0;}