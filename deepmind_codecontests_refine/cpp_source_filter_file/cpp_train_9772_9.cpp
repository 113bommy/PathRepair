#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  bool n,w,s,e;
  n=s=w=e=false;
  for(int i=0;i<s.size();i++){
    if(s[i]=='S') s=true;
    if(s[i]=='W') w=true;
    if(s[i]=='E') e=true;
    if(s[i]=='N') n=true;
  }
  if(w==e&&s==n) cout<<"Yes";
  else cout<<"No";
}