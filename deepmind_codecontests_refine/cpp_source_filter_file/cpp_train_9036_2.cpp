#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin>>s;
  long int x,ans;
  x=ans=0;
  for(long int i=0;i<s.size();i++){
    if(s.at(i)=='B')x++;
    if(s.at(i)=='W')ans+=x;
  cout<<ans<<endl;
}
