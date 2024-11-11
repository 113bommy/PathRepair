#include <bits/stdc++.h>
using namespace std;
int n;
int a[400005];
int dep[400005];
int l[400005], r[400005];
vector<int> atl[400005], atr[400005];
stack<int> s;
int tree[4 * 400005], lazy[4 * 400005];
void lazify(int s, int e, int i) {
  if (lazy[i]) {
    tree[i] += lazy[i];
    if (s != e) {
      lazy[2 * i] += lazy[i];
      lazy[2 * i + 1] += lazy[i];
    }
    lazy[i] = 0;
  }
}
void upd(int l, int r, int s, int e, int i, int x) {
  lazify(s, e, i);
  if (s > r || e < l || l > r) return;
  if (s >= l && e <= r) {
    lazy[i] += x;
    lazify(s, e, i);
    return;
  }
  int mid = (s + e) >> 1;
  upd(l, r, s, mid, 2 * i, x);
  upd(l, r, mid + 1, e, 2 * i + 1, x);
  tree[i] = max(tree[2 * i + 1], tree[2 * i]);
}
int qur(int l, int r, int s, int e, int i) {
  if (l == 0 || s > r || e < l) return 0;
  lazify(s, e, i);
  if (s >= l && e <= r) return tree[i];
  int mid = (s + e) >> 1;
  return max(qur(l, r, s, mid, 2 * i), qur(l, r, mid + 1, e, 2 * i + 1));
}
void rec(int i, int d) {
  dep[i] = d;
  int x = -1, y = -1;
  if (atr[i].size()) x = atr[i][0];
  if (atl[i].size()) y = atl[i].back();
  if (x != -1) rec(x, d + 1);
  if (y != -1) rec(y, d + 1);
}
void preprocess() {
  for (int i = 1; i <= 2 * n; i++) {
    while (s.size() && a[s.top()] >= a[i]) s.pop();
    if (s.size())
      l[i] = s.top();
    else
      l[i] = 0;
    if (i <= n) atl[l[i]].push_back(i);
    s.push(i);
  }
  while (s.size()) s.pop();
  for (int i = 2 * n; i >= 1; i--) {
    while (s.size() && a[s.top()] >= a[i]) s.pop();
    if (s.size())
      r[i] = s.top();
    else
      r[i] = 2 * n + 1;
    if (i <= n) atr[r[i]].push_back(i);
    s.push(i);
  }
  for (int i = 0; i <= 2 * n + 1; i++) {
    sort(atr[i].begin(), atr[i].end());
    sort(atl[i].begin(), atl[i].end());
  }
  for (int i = 1; i <= n; i++)
    if (a[i] == 1) rec(i, 1);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i], a[n + i] = a[i];
  preprocess();
  for (int i = 1; i <= n; i++) upd(i, i, 1, 2 * n, 1, dep[i]);
  int ans = qur(1, n, 1, 2 * n, 1);
  int shift = 0;
  for (int i = 1; i < n; i++) {
    int L = i + 1;
    int R = min(i + n - 1, r[i] - 1);
    upd(L, R, 1, 2 * n, 1, -1);
    L = max(i + 1, l[i + n] + 1);
    R = i + n - 1;
    upd(L, R, 1, 2 * n, 1, 1);
    upd(i + n, i + n, 1, 2 * n, 1, qur(l[i + n], l[i + n], 1, 2 * n, 1) + 1);
    int cur = qur(i + 1, i + n, 1, 2 * n, 1);
    if (ans > cur) ans = cur, shift = i;
  }
  cout << ans << " " << shift << '\n';
  return 0;
}
