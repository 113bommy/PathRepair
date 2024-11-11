#include <bits/stdc++.h>
using namespace std;
int main() {
  string s; cin>>s; int x=0;
  for(int i=0;i<s.size()/2;i++){
    if(s.at(i)!=s.at(s.size()-i-1)) x++;
  }
  cout<<x<<endl;
}