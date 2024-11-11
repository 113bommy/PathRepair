#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  size_t sz=s.size();
  for(i=0;i<sz;i++)if(((s[i]=='L')&(i^0))||((s[i]=='R')&(i&1))){cout<<"No"<<endl;return 0;}
  cout<<"Yes"<<endl;
  return 0;
}
