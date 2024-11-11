#include <bits/stdc++.h>


using namespace std;

//#define push_back pb
int main()
{int n,k;
 cin>>n>>k;
 vector<int>v(n);
 for(int i=0;i<n;i++)
   cin>>v[i];
 vector<bool>dp(k+1);
 for(int stones=0;stones<=k;stones++)
  for(int x:v){
    if(stones>=x && !dp[stones-x])
      dp[stones]=1;
  }
 
    
 puts(dp[k]?"First":"Second");
  
     return 0;
}