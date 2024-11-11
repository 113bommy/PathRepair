#include <bits/stdc++.h>
using namespace std;
const int INF = (int)1e9;
int solve[5];
int v[5], p[5];
int n;
int mask[5];
pair<int, int> ddr[5] = {{1, 2}, {1, 4}, {1, 8}, {1, 16}, {1, 32}};
int costs[5] = {500, 1000, 1500, 2000, 2500};
int get_max_val(int task, long long all) {
  long long have = solve[task];
  for (int i = 0; i < 5; ++i) {
    if (have * ddr[i].second > all * ddr[i].first) return costs[i];
  }
  return 3000;
}
const int ITER = (int)1e5;
bool test(int ppl) {
  for (int i = 0; i < 5; ++i) {
    solve[i] += mask[i] * ppl;
  }
  int all = n + ppl;
  int vpnts = 0;
  int ppnts = 0;
  for (int i = 0; i < 5; ++i) {
    int cost = get_max_val(i, all);
    if (v[i] != -1) {
      vpnts += (cost / 250) * (250 - v[i]);
    }
    if (p[i] != -1) {
      ppnts += (cost / 250) * (250 - p[i]);
    }
  }
  bool ans = (vpnts > ppnts);
  for (int i = 0; i < 5; ++i) {
    solve[i] -= mask[i] * ppl;
  }
  return ans;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 5; ++j) {
      int a;
      cin >> a;
      if (i == 0) v[j] = a;
      if (i == 1) p[j] = a;
      if (a != -1) {
        solve[j]++;
      }
    }
  }
  int ans = INF + 7;
  for (int ms = 0; ms < 32; ++ms) {
    for (int i = 0; i < 5; ++i) {
      if (ms & (1 << i)) {
        if (v[i] == -1) {
          mask[i] = 0;
        } else {
          mask[i] = 1;
        }
      } else {
        mask[i] = 0;
      }
    }
    bool flag = false;
    for (int i = 0; i < ITER; ++i) {
      if (test(i)) {
        ans = min(ans, i);
        flag = true;
        break;
      }
    }
    if (flag) continue;
    int l = ITER - 2;
    int r = INF + 7;
    if (!test(r)) {
      continue;
    }
    while (r - l > 1) {
      int m = (r + l) / 2;
      if (test(m))
        r = m;
      else
        l = m;
    }
    ans = min(ans, r);
  }
  if (ans == INF + 7) ans = -1;
  cout << ans << endl;
  return 0;
}
