#include<bits/stdc++.h>
using namespace std;

int main() {
int n;
  cin>>n;
 int a=0,b=0,c=0; 
 while(n--)
 {int dp[3]={0};
   int i,j,k;
  cin>>i>>j>>k;
  dp[0]=i+max(b,c);
  dp[1]=j+max(a,c);
  dp[2]=k+max(a,b);
  a=dp[0];
  b=dp[1];
  c=dp[2];
 }
  cout<<max(max(a,b),c);
}
