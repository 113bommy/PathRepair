#include<bits/stdc++.h>
using namespace std;
int main(void){
  int n;
  string s;
  cin>>n;
  map<string,int> mp;
  int m=0;
  while(n--){
    cin>>s;
    if(mp.find(s)==mp.end()){
      mp[s]=1;
    }else{
      ++mp[s];
    }
    m=max(m,mp[3]);
  }
  for(auto i:mp){
    if(i.second==m){
      cout<<i.first<<endl;
    }
  }
  return 0;
}