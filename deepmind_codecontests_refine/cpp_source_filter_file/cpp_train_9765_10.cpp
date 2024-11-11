#include <bits/stdc++.h>
using namespace std;

int main(){
  	cin >> n;
  map<string,int> mp;
  long long ans = 0;
  for(int i = 0; i < n; i++){
  	string s;	cin >> s;
    sort(s.begin(),s.end());
    ans += mp[s];
    mp[s]++;
  }
  cout << ans << '\n';
  return 0;
}