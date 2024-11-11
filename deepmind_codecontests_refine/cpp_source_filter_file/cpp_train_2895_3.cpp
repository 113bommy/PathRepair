#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int ans=0;
  for(int i=1;i<s.size();i++){
    if(s.at(i)==s.at(i-1)){
      ans++;
      if(s.at(i)=='0') s.at(i)='1';
      else s.at(i)='0'
    }
  }
  cout << ans << endl;
}
