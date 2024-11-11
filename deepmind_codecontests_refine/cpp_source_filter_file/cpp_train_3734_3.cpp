#include<bits/stdc++.h>
using namespace std;
int main(){
  int c[26]={};
  bool f=true;
  string w;cin>>w;
  int i;
  for(i=0;i<w.size();i++) c[s[i]-'a']++;
  for(i=0;i<26;i++) f&=(c[i]%2==0);
  cout << (f:"Yes":"No") << endl;
  return 0;
}
