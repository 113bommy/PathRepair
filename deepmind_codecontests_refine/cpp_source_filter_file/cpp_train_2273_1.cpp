#include<bits/stdc++.h>

using namespace std;

#define int long long

int32_t main(){
  int n;
  cin>>n;
  
  map<int,int>m;
  int temp;
  for(int i=0;i<n;i++){
    cin>>temp;
    m[temp]++;
  }
  int ans = 0;
  
  for(auto it : m){
    if(it.first > it.second) ans += it.second;
    else if(it.second > it.first) ans += (it.second - it.first);
  }
  cout<<ans;