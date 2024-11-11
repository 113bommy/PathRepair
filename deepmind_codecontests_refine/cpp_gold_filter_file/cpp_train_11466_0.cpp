#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n;
  cin >> n;
  map<int, int> mp;
  long long ans = 0;
  for (long long i = 0; i < n; i++) {
    string s;
    cin >> s;
    long long n = s.size(), sm = 0, mn_sm = 10123444LL;
    for (long long i = 0; i < n; i++) {
      sm += s[i] == '(' ? 1 : -1;
      mn_sm = min(mn_sm, sm);
    }
    if (mn_sm < 0 && mn_sm < sm) continue;
    if (mp.find(-sm) != mp.end()) {
      mp[-sm]--;
      if (mp[-sm] == 0) mp.erase(mp.find(-sm));
      ans++;
    } else if (mp.find(sm) == mp.end())
      mp[sm] = 1;
    else
      mp[sm]++;
  }
  cout << ans;
  return 0;
}
