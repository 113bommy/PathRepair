#include <bits/stdc++.h>
using namespace std;
int main(){
  int x;
  cin>>x;
  string s;
  cin>>s;
  if(s.substr(0,x/2)==s.substr(x/2,s.size()))
      cout<<"Yes";
  else 
      cout<<"No";
  return 0;
}
