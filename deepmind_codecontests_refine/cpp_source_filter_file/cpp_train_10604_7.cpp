#include<bits/stdc++.h>
using namespace std;
int main(){
  string s,t="CODEFESTIVAL2016;
  cin>>s;
  int ans=0;
  for(int i=0;i<s.length();i++)
    if(s[i]!=t[i]) ans++;
  cout<<ans;
}