#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int maxn = 403;
int n, m;
int a[maxn][maxn];
void read() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> a[i][j];
}
int min_r[maxn];
long long s[maxn * maxn][7];
int find_first_bit(long long num) { return 63 - __builtin_clzll(num & -num); }
int find_last_bit(long long num) { return 63 - __builtin_clzll(num); }
int find_prev(int c, int idx) {
  int pos = idx / 63;
  idx %= 63;
  long long left = (s[c][pos] & ((1ll << idx) - 1));
  if (left) return pos * 63 + find_last_bit(left);
  for (int i = pos - 1; i >= 0; i--)
    if (s[c][i]) return i * 63 + find_last_bit(s[c][i]);
  return -1;
}
int find_next(int c, int idx) {
  int pos = idx / 63;
  idx %= 63;
  long long curr = (s[c][pos] >> (idx + 1));
  if (curr) return pos * 63 + idx + 1 + find_first_bit(curr);
  for (int i = pos + 1; i < 7; i++)
    if (s[c][i]) return i * 63 + find_first_bit(s[c][i]);
  return -1;
}
void solve() {
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) min_r[j] = m + 1;
    for (int j = 1; j < maxn * maxn; j++)
      for (int k = 0; k < 7; k++) s[j][k] = 0;
    for (int j = i; j <= n; j++) {
      for (int k = 1; k <= m; k++) {
        int pos = (k - 1) / 63, r = (k - 1) % 63;
        if (s[a[j][k]][pos] & (1ll << r))
          min_r[k] = k;
        else {
          s[a[j][k]][pos] ^= (1ll << r);
        }
      }
      for (int k = 1; k <= m; k++) {
        int f1 = find_prev(a[j][k], k - 1), f2 = find_next(a[j][k], k - 1);
        if (f1 != -1) min_r[f1 + 1] = min(min_r[f1 + 1], k);
        if (f2 != -1) min_r[k] = min(min_r[k], f2 + 1);
      }
      int curr = m + 1;
      for (int k = m; k >= 1; k--) {
        curr = min(curr, min_r[k]);
        ans = max(ans, (curr - k) * (j - i + 1));
      }
    }
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  read();
  solve();
}
