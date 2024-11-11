#include <bits/stdc++.h>
using namespace std;
int n, s, l;
vector<int> a;
vector<int> mn;
vector<int> mx;
vector<int> dpmn;
void build(int tl, int tr, int v) {
  if (tl == tr) {
    mn[v] = a[tl];
    mx[v] = a[tr];
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
  int left = 0, right = r;
  while (left + 1 < right) {
    int mid = (left + right) >> 1;
    if (get(mid, r) <= s)
      right = mid;
    else
      left = mid;
  }
  return (get(left, r) <= s ? left : right);
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
  for (int i = 0; i < l - 1; i++) {
    dp[i] = INT_MAX;
    update(0, n - 1, 1, i, INT_MAX);
  }
  for (int i = l - 1; i < n; i++) {
    if (get(0, i) <= s) {
      dp[i] = 1;
      update(0, n - 1, 1, i, dp[i]);
      continue;
    }
    int idx = src(i);
    if (idx - 1 > i - l) {
      dp[i] = INT_MAX;
      update(0, n - 1, 1, i, INT_MAX);
      continue;
    }
    dp[i] = getmn(0, n - 1, 1, idx - 1, i - l, 1);
    if (dp[i] != INT_MAX) dp[i]++;
    update(0, n - 1, 1, i, dp[i]);
  }
  cout << (dp[n - 1] == INT_MAX ? -1 : dp[n - 1]) << '\n';
  return 0;
}
