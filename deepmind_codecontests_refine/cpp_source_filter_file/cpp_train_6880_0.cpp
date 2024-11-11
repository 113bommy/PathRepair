#include <bits/stdc++.h>
using namespace std;
const int maxn = 22;
const long long inf = 2e9 + 1;
int n, p, ones;
struct let {
  int l, r, t;
  int id;
} arr[maxn];
bool comp(let a, let b) { return a.l < b.l; }
int dp[1 << maxn];
int nxt[1 << maxn];
int rec[1 << maxn];
int ans[maxn][2];
void go(int mask, int pass) {
  if (!mask) return;
  int i = rec[mask];
  int j = arr[i].id;
  ans[j][0] = pass;
  ans[j][1] = dp[mask] - arr[i].t;
  go(mask ^ (1 << i), pass);
}
int main() {
  cin >> n >> p;
  ones = (1 << n) - 1;
  for (int i = 0; i < n; i++) {
    cin >> arr[i].l >> arr[i].r >> arr[i].t;
    arr[i].r += arr[i].l;
    arr[i].id = i;
  }
  sort(arr, arr + n, comp);
  dp[0] = 1;
  for (int mask = 1, tmp; mask < (1 << n); mask++) {
    tmp = inf;
    bool ok[n];
    for (int i = 0; i < n; i++) ok[i] = !!(mask & (1 << i));
    for (int i = 0, j, x, len; i < n; i++) {
      if (mask & (1 << i)) {
        x = dp[mask ^ (1 << i)], j, len = arr[i].t;
        for (j = 0; j < n; j++) {
          if (x >= arr[j].l && x < arr[j].r) x = arr[j].r;
          if (x < arr[j].l && x + len >= arr[j].l && ok[i]) x = arr[j].r;
        }
        if (arr[i].l > x + len && x + len < tmp) {
          tmp = x + len;
          rec[mask] = i;
        }
      }
    }
    dp[mask] = tmp;
  }
  if (p == 1) {
    if (dp[ones] < inf) {
      cout << "YES" << endl;
      go(ones, 1);
      for (int i = 0; i < n; i++) {
        cout << ans[i][0] << " " << ans[i][1] << endl;
      }
    } else {
      cout << "NO" << endl;
    }
  } else {
    int mnm = inf, id = 0;
    for (int i = 0; i < (1 << n); i++) {
      int j = ones ^ i;
      if (max(dp[i], dp[j]) < mnm) {
        mnm = max(dp[i], dp[j]);
        id = i;
      }
    }
    if (mnm < inf) {
      cout << "YES" << endl;
      go(id, 1);
      go(ones ^ id, 2);
      for (int i = 0; i < n; i++) {
        cout << ans[i][0] << " " << ans[i][1] << endl;
      }
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
