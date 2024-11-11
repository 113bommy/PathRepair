#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  string s;cin >> s;
  ll n = s.size(),i,b = 0,ans = 0;
  for(i=0;i<n;i++){
    if(s[i]=='B') b++;
    else ans += b;
  }
  cout << ans << "\n";
