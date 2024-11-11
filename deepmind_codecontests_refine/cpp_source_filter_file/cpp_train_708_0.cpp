#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b;
  string s;
  cin>>a>>b>>s;
  string ans="Yes";
  for(int i=0;i<a;i++){
    if(s[i]=='-') ans="No";
  }
  if(s[a]!="-") ans="No";
  for(int i=0;i<b;i++){
    if(s[a+1+i]=='-') ans="No";
  }
  cout<<ans<<endl;
}
