#include<bits/stdc++.h>
using namespace std;
int main(){
  string s,s2; cin>>s>>s2;
  int len=s.length();
  int c=0;
  for(int i=0;i<len;i++)
    if(s[i]!=s2[i])
      c++;
  cout<<c;
}
