#include <bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin >> s;
  int ans=999;
  for (int i=0;i<s.size()-2;i++){
    int t=(s[i]-'0')*100+(s[i+1]-'0')*10+s[i+2]-'0';
    ans=min(ans,abs(t-753));
  }
  cout << ans << endl;
}