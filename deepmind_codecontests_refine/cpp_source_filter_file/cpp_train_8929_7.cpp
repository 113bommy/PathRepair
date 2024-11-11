#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;#
  map<string,int> mp;
  for(int i=0;i<N;i++){
    string s;
    cin>>s;
    mp[s]++;
  }
  int mx=0;
  for(auto x:mp){
    mx=max(mx,x.second);
  }
  for(auto t:mp){
    if(mx==t.second){
      cout<<t.first<<endl;
    }
  }
  return 0;
}
      