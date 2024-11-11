#include <bits/stdc++.h>
using namespace std;
const int maxn = 300 * 1000 + 5;
int n;
pair<int, int> v[maxn];
int P[maxn][3];
int check(int m) {
  int t[3][2];
  memset(t, 0, sizeof t);
  for (int i = 0; i < (3); ++i) {
    if (m & (1 << (2 * i))) {
      t[i][0]++;
      t[(i + 1) % 3][0]--;
    } else {
      t[i][0]--;
      t[(i + 1) % 3][0]++;
    }
    if (m & (1 << (2 * i + 1))) {
      t[i][1]++;
      t[(i + 1) % 3][1]--;
    } else {
      t[i][1]--;
      t[(i + 1) % 3][1]++;
    }
  }
  for (int i = 0; i < (n); ++i)
    for (int j = 0; j < (3); ++j)
      P[i][j] = t[j][0] * v[i].first + t[j][1] * v[i].second;
  int b0, b1, b2;
  for (int i = 0; i < (n); ++i) {
    if (i == 2)
      b2 = b1 + P[i][2];
    else
      b2 = max(b2, b1 + P[i][2]);
    if (i == 1)
      b1 = b0 + P[i][1];
    else
      b1 = max(b1, b0 + P[i][1]);
    if (i == 0)
      b0 = P[i][0];
    else
      b0 = max(b0, P[i][0]);
  }
  return b2;
}
void solve() {
  cin >> n;
  for (int i = 0; i < (n); ++i) cin >> v[i].first >> v[i].second;
  int mix = v[0].first, mx = v[0].first, miy = v[0].second, my = v[0].second;
  for (int i = 0; i < (n); ++i) {
    mix = min(mix, v[i].first);
    mx = max(mx, v[i].first);
    miy = min(miy, v[i].second);
    my = max(my, v[i].second);
  }
  int best = 0;
  for (int i = 0; i < ((1 << 6)); ++i) best = max(best, check(i));
  cout << best;
  for (int i = 4; i <= n; ++i) cout << " " << 2 * (mx - mix + my - miy);
  cout << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  while (t--) solve();
  return 0;
}
