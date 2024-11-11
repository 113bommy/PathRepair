#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
vector<pair<int64_t,int64_t>>A(N);
  for(int64_t i=0;i<N;i++){
  int64_t a; cin>>a;
    pair<int64_t,int64_t>p(a,i);
    A.at(i)=p;
  
  }sort(A.begin(),A.end());
  int64_t dp[N][N];
  for(int64_t j=0;j<N;j++)
    dp[0][j]=A[0].first*abs(j-A[0].second);
  for(int64_t i=1;i<N;i++){
  for(int64_t j=0;j<N-i;j++){
  dp[i][j]=
    max(dp[i-1][j]+A[i].first*abs(A[i].second-i-j),A[i].first*abs(A[i].second-j)+dp[i-1][j+1])
  
  }
  
  }cout<<dp[N-1][0]<<endl;
   return 0;
}