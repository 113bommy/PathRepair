#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
int n, s, l;
vector<int> a;
vector<int> mn;
vector<int> mx;
vector<int> dpmn;
void build(int tl, int tr, int v) {
  if (tl == tr) {
    mn[v] = a[tl];
    mx[v] = a[tl];
    return;
  }
  int mid = (tl + tr) >> 1;
  build(tl, mid, v << 1);
  build(mid + 1, tr, v << 1 | 1);
  mn[v] = min(mn[v << 1], mn[v << 1 | 1]);
  mx[v] = max(mx[v << 1], mx[v << 1 | 1]);
}
int getmn(int tl, int tr, int v, int l, int r, bool flag) {
  if (l > tr || r < tl) return INT_MAX;
  if (l <= tl && tr <= r) return (flag == 0 ? mn[v] : dpmn[v]);
  int mid = (tl + tr) >> 1;
  return min(getmn(tl, mid, v << 1, l, r, flag),
             getmn(mid + 1, tr, v << 1 | 1, l, r, flag));
}
int getmx(int tl, int tr, int v, int l, int r) {
  if (l > tr || r < tl) return -INT_MAX;
  if (l <= tl && tr <= r) return mx[v];
  int mid = (tl + tr) >> 1;
  return max(getmx(tl, mid, v << 1, l, r),
             getmx(mid + 1, tr, v << 1 | 1, l, r));
}
int get(int l, int r) {
  return (getmx(0, n - 1, 1, l, r) - getmn(0, n - 1, 1, l, r, 0));
}
int src(int r) {
  int left = -1, right = r + 1;
  while (right - left > 1) {
    int mid = (left + right) >> 1;
    if (get(mid + 1, r) <= s)
      right = mid;
    else
      left = mid;
  }
  return right;
}
void update(int tl, int tr, int v, int i, int x) {
  if (i < tl || i > tr) return;
  if (tl == tr) {
    dpmn[v] = x;
    return;
  }
  int mid = (tl + tr) >> 1;
  update(tl, mid, v << 1, i, x);
  update(mid + 1, tr, v << 1 | 1, i, x);
  dpmn[v] = min(dpmn[v << 1], dpmn[v << 1 | 1]);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> s >> l;
  if (l > n) {
    cout << -1 << '\n';
    return 0;
  }
  a.resize(n), mn.resize(4 * n), mx.resize(4 * n), dpmn.resize(4 * n);
  for (int i = 0; i < n; i++) cin >> a[i];
  build(0, n - 1, 1);
  vector<int> dp(n);
  for (int i = 0; i < n; i++) {
    dp[i] = inf;
    update(0, n - 1, 1, i, inf);
  }
  for (int i = l - 1; i < n; i++) {
    if (get(0, i) <= s) {
      dp[i] = 1;
      update(0, n - 1, 1, i, dp[i]);
      continue;
    }
    int idx = src(i);
    if (idx > i - l) continue;
    dp[i] = getmn(0, n - 1, 1, idx, i - l, 1) + 1;
    update(0, n - 1, 1, i, dp[i]);
  }
  cout << (dp[n - 1] > n ? -1 : dp[n - 1]) << '\n';
  return 0;
}
