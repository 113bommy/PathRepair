#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[300001][8];
int buildMask(int k) {
  int mask = 0;
  for (int x = 0; x < m; x++) {
    if (k & (1 << x)) {
      mask = mask & ~(1 << x);
    } else {
      mask = mask | (1 << x);
    }
  }
  return mask;
}
pair<int, int> check(int v) {
  int combo[(int)pow(2, m) + 1];
  memset(combo, 0, sizeof combo);
  for (int x = 0; x < n; x++) {
    int mask = 0;
    for (int y = 0; y < m; y++) {
      if (arr[x][y] >= v) {
        mask = mask | (1 << y);
        combo[mask] = x + 1;
      }
    }
    int nMask = buildMask(mask);
    if (nMask == 0) return make_pair(x + 1, x + 1);
    int loo = pow(2, m);
    for (int y = 0; y < loo; y++) {
      if (combo[y] && (y & nMask) == nMask) return make_pair(x + 1, combo[y]);
    }
  }
  return make_pair(0, 0);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  for (int x = 0; x < n; x++) {
    for (int y = 0; y < m; y++) cin >> arr[x][y];
  }
  long long lo = 0;
  long long hi = 1e9;
  pair<int, int> ans;
  long long val = -1;
  while (lo <= hi) {
    long long mid = (lo + hi) / 2;
    pair<int, int> cur = check(mid);
    if (cur.first != 0) {
      lo = mid + 1;
      if (mid > val) ans = cur;
      val = max(val, mid);
    } else {
      hi = mid - 1;
    }
  }
  cout << ans.first << " " << ans.second << endl;
}
