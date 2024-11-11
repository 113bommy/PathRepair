#include <bits/stdc++.h>
using namespace std;
int n, S, l, a[100005], k[100005], dp[100005];
pair<int, int> second[400005];
void build(int v, int l, int r) {
  if (l == r) {
    second[v] = {a[l], a[l]};
    return;
  }
  int mid = (l + r) / 2;
  build(v * 2, l, mid);
  build(v * 2 + 1, mid + 1, r);
  second[v].first = min(second[v * 2].first, second[v * 2 + 1].first);
  second[v].second = max(second[v * 2].second, second[v * 2 + 1].second);
}
void upd(int v, int l, int r, int x, int p) {
  if (l == r) {
    second[v] = {p, p};
    return;
  }
  int mid = (l + r) / 2;
  if (x <= mid)
    upd(v * 2, l, mid, x, p);
  else
    upd(v * 2 + 1, mid + 1, r, x, p);
  second[v].first = min(second[v * 2].first, second[v * 2 + 1].first);
  second[v].second = max(second[v * 2].second, second[v * 2 + 1].second);
}
pair<int, int> get(int v, int A, int B, int l, int r) {
  if (l > B || r < A) return {1000000009, -1000000009};
  if (A == l && B == r) return second[v];
  int mid = (A + B) / 2;
  pair<int, int> L = get(v * 2, A, mid, l, min(mid, r));
  pair<int, int> R = get(v * 2 + 1, mid + 1, B, max(mid + 1, l), r);
  return {min(L.first, R.first), max(L.second, R.second)};
}
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> S >> l;
  for (int i = 1; i <= n; i++) cin >> a[i];
  build(1, 1, n);
  for (int i = 1; i <= n; i++) {
    int l = 0, r = i + 1;
    while (r - l > 1) {
      int mid = (l + r) / 2;
      pair<int, int> c = get(1, 1, n, mid, i);
      if (c.second - c.first <= S)
        r = mid;
      else
        l = mid;
    }
    k[i] = r;
  }
  memset(second, 63, sizeof(second));
  memset(dp, 63, sizeof(dp));
  for (int i = l; i <= n; i++)
    if (i - k[i] + 1 >= l) {
      if (k[i] == 1)
        dp[i] = 1;
      else {
        int c = get(1, 1, n, k[i] - 1, i - 1).first;
        dp[i] = c + 1;
      }
      upd(1, 1, n, i, dp[i]);
    }
  cout << (dp[n] > 1000000009 ? -1 : dp[n]) << endl;
  return 0;
}
