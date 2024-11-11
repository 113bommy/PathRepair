#include<bits/stdc++.h>
using namespace std;
 
int main() {
  int ret=0;
  string s; cin>>s;
  for(int i=1;i<s.size();++i)
    if(s[i]!=s[i-1])
      ret++;
  cout<<ret<<"\n";
  return 0;
}