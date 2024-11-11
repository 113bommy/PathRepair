#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  string ans = "Yes";
  for(int i=0;i<s.size();++i){
    if((i%2==0&&s[i]=='L')||(i%2==1&&s[i]=='R')){
      ans="No";
      break;
    }
  }
  cout << ans << endl;
  return 0;
}