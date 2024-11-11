#include<bits/stdc++.h>
using namespace std;
const int c[]={0,2,5,5,4,5,6,3,7,6};
string stmax(string a, string b)
{
  if(a.size() > b.size())
  {
    return a;
  }
  else if(a.size() < b.size())
  {
      return b;
  }
  else{
  	if(a>=b)return a;
    else return b;
  }
}
    
int main(){
  int n,m;
  cin>>n>>m;
  int a[m];
  for(int i=0; i<m; i++){
    cin>>a[i];
  }
  vector<string>dp(10101,"");
  for(int i=0; i<=n; i++){
    for(int j=0; j<m; j++){
      if(i==0||dp[i]!=""){			//
        dp[i+c[a[j]]]=stmax(dp[i]+to_string(a[j]),dp[i+c[a[j]]]);
      }
    }
  }
  cout<<dp[n]<<endl;
}
    
  
   
