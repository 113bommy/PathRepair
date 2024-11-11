#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-8;
const int INF = 0x3F3F3F3F;
const int64_t LINF = 4611686018427387903;
const int MOD = 1e9 + 7;
int peo[1 << 9], mn[1 << 9];
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  int n, m, mx = 0;
  cin >> n >> m;
  memset(mn, 0x3f, sizeof mn);
  vector<int> arr(n);
  vector<pair<int, int>> brr(m);
  for (int i = 0; i < n; i++) {
    int w, res = 0;
    cin >> w;
    while (w--) {
      int x;
      cin >> x;
      res |= (1 << (x - 1));
    }
    arr[i] = res;
  }
  for (int i = 0; i < m; i++) {
    int w, res = 0;
    cin >> brr[i].first >> w;
    while (w--) {
      int x;
      cin >> x;
      res |= (1 << (x - 1));
    }
    brr[i].second = res;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < (1 << 9); j++) {
      if ((j & arr[i]) == arr[i]) peo[j]++;
    }
  }
  int ans = 0, cur = INF;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < (1 << 9); j++) {
      int res = j | brr[i].second;
      if (mn[j] == INF) continue;
      if (peo[res] > mx) mx = peo[res], cur = INF;
      if (peo[res] == mx) {
        if (brr[i].first + mn[j] < cur) {
          cur = brr[i].first + mn[j];
          ans = i;
        }
      }
    }
    for (int j = 0; j < (1 << 9); j++) {
      if ((j & brr[i].second) == j) mn[j] = min(mn[j], brr[i].first);
    }
  }
  for (int i = 0; i < m; i++) {
    if (i == ans) continue;
    if (peo[brr[i].second | brr[ans].second] == mx &&
        brr[i].first + brr[ans].first == cur) {
      cout << i + 1 << ' ' << ans + 1 << '\n';
      ;
      return 0;
    }
  }
  return 0;
}
