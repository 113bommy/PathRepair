#include<bits/stdc++.h>
using namespace std;
int main(){
  string s,t;cin>>s>>t;
  sort(s,begin(),end());
  sort(t,begin(),end());
  if(s<t)cout<<"Yes";else cout<<"No";}