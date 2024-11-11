#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m;cin>>n>>m;
  vector<int> b(m,0);
  for(int i=0;i<n;i++){
    int k;cin>>k;
    for(int j=0;j<k;j++){
      int a;cin>>a;a++
      b[a]++;}}
  int ans=0;
  for(int i=0;i<n;i++){
    if(b[i]==n)ans++;}
  cout<<ans;}