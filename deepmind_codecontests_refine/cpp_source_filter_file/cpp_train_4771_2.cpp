ude <bits/stdc++.h>
using namespace std;
#define inf (1<<16)

int main(){
  int n;
  cin>>n;
  int a[12]={1,6,9,36,81,216,729,1296,6561,7776,46656,59049};
  vector<int> dp(n+1,inf);
  dp[0]=0;

  for(int i=0;i<=n;++i){
    for(int j=0;j<12;++j){
      if(i+a[j]<=n)dp[i+a[j]]=min(dp[i+a[j]],dp[i]+1);
    }
  }
  cout<<dp[n]<<endl;
}
