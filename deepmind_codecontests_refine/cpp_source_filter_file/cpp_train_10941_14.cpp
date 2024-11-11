#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  int x, y;
  pair<int, int> a[1005];
  for (int i = 0; i < n; ++i) {
    cin >> x >> s;
    y = 0;
    for (int j = 0; j < s.size(); ++j) y |= (1 << (s[j] - 'A'));
    a[i] = make_pair(x, y);
  }
  sort(a, a + n);
  int sum, vi, ans = 1e9 + 1;
  for (int i = 0; i < n; ++i) {
    sum = a[i].first;
    vi = a[i].second;
    for (int j = 0; j < n; ++j) {
      if (vi == 7) break;
      if (a[j].second | vi > vi) {
        sum += a[j].first;
        vi = a[j].second | vi;
      }
    }
    if (vi == 7) ans = min(sum, ans);
  }
  if (ans < 1e9 + 1)
    cout << ans;
  else
    cout << -1;
  return 0;
}
