#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
const long long INF = 1e18;
const int MAXN = 5e5 + 1;
int cnt[MAXN], cntd[MAXN];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m, k, s;
  cin >> m >> k >> n >> s;
  int a[m];
  for (auto &i : a) cin >> i;
  for (int i = 0; i < s; i++) {
    int f;
    cin >> f;
    cntd[f]++;
  }
  int need = 0, r = 0;
  while (need < s and r < m) {
    if (cnt[a[r]] < cntd[a[r]]) need++;
    cnt[a[r]]++;
    r++;
  }
  if (need < s) {
    cout << -1;
    return 0;
  }
  for (int l = 0; l < m; l++) {
    int d = r - l;
    if (l / k + (m - r) / k >= n - 1) {
      if (d < k) d = k;
      cout << d - k << '\n';
      for (int i = l; i < r and d > k; i++) {
        if (cnt[a[i]] > cntd[a[i]]) cout << i + 1 << ' ', d--, cnt[a[i]]--;
      }
      return 0;
    }
    cnt[a[l]]--;
    while (cnt[a[l]] < cntd[a[l]] and r < m) cnt[a[r++]]++;
    if (cnt[a[l]] < cntd[a[l]]) break;
  }
  cout << -1;
  return 0;
}
