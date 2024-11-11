#include <bits/stdc++.h>
using namespace std;
int cnt1[10], cnt2[10], ans(1e9);
int main() {
  string s, t;
  cin >> t >> s;
  for (auto ch : s) cnt1[ch - '0']++;
  for (auto ch : t) cnt2[ch - '0']++;
  cnt1[6] += cnt1[9], cnt2[6] += cnt2[9];
  cnt1[2] += cnt1[5], cnt1[5] = 0;
  cnt2[2] += cnt2[5], cnt2[5] = 0;
  for (int i = 0; i < 8; i++)
    if (cnt2[i]) ans = min(cnt1[i] / cnt2[i], ans);
  cout << ans << endl;
  return 0;
}
