#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;cin>>n;string s="";
  map <string,int>mp;
  for(int i=0;i<n;i++){cin>>s;mp[s]++;}
  cin>>n;
  while(cin>>s)mp[s]--;
  int ans=0;
  for(auto x:mp){ans=max(ans, x.second);}
  cout<<ans<<endl;
}
