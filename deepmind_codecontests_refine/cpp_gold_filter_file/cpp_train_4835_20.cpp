#include <bits/stdc++.h>
using namespace std;
int n, m, k, a[101][101];
int solve1() {
  int ans = 100000;
  for (int t = 0; t < (n); ++t) {
    int here = 0, cur;
    for (int i = 0; i < (n); ++i) {
      cur = 0;
      for (int j = 0; j < (m); ++j) cur += a[i][j] ^ a[t][j];
      here += min(cur, m - cur);
    }
    ans = min(ans, here);
  }
  return (ans > k ? -1 : ans);
}
bool get(int s, int pos) { return (s & (1 << pos)); }
int solve2() {
  int ans = 100000;
  for (int s = 0, p = (1 << m); s < p; ++s) {
    int here = 0, cur;
    for (int i = 0; i < (n); ++i) {
      cur = 0;
      for (int j = 0; j < (m); ++j) cur += get(s, j) ^ a[i][j];
      here += min(cur, m - cur);
    }
    ans = min(ans, here);
  }
  return (ans > k ? -1 : ans);
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m >> k;
  for (int i = 0; i < (n); ++i)
    for (int j = 0; j < (m); ++j) cin >> a[i][j];
  if (m > 10)
    cout << solve1() << '\n';
  else
    cout << solve2() << '\n';
  return 0;
}
