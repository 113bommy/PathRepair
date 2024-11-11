#include<iostream>
using namespace std;
int main() {
  int k;
  string s;
  cin>>k>>s;
  k=min(k,s.size());
  for(int i=0;i<k;++i)cout<<s[i];
  if(k<s.size())cout<<'...'<<endl;
}