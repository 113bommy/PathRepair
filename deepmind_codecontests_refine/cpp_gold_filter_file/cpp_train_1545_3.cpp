#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  string s;
  cin>>n;
  map<string,int> mp;
  for(int i=0;i<n;i++){
    cin>>s;
    mp[s]++;
  }
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>s;
    mp[s]--;
  }
  int c=0;
  for(auto a:mp){
    c=max(c,a.second);
  }
  cout<<c<<endl;
}