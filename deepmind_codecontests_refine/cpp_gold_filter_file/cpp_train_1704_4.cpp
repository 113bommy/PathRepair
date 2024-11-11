#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const int inf = INT_MAX;
const long long mod = 1e9 + 7;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};
const int N = 1e5 + 5;
const int A = 26;
long long t[4 * N][22], p[4 * N], a[N];
void push(int v, int tl, int tr) {
  if (tl != tr) {
    p[v * 2] ^= p[v];
    p[v * 2 + 1] ^= p[v];
  }
  for (int i = 0; i <= 20; i++) {
    if ((p[v] >> i) & 1) t[v][i] = tr - tl + 1 - t[v][i];
  }
  p[v] = 0;
}
void build(int v, int tl, int tr) {
  if (tl == tr) {
    for (int i = 0; i <= 20; i++) {
      if ((a[tl] >> i) & 1) t[v][i] = 1;
    }
    return;
  }
  int tm = (tl + tr) / 2;
  build(v * 2, tl, tm);
  build(v * 2 + 1, tm + 1, tr);
  for (int i = 0; i <= 20; i++) {
    t[v][i] = t[v * 2][i] + t[v * 2 + 1][i];
  }
}
long long sum(int v, int tl, int tr, int l, int r) {
  push(v, tl, tr);
  if (l > r || tr < l || tl > r) return 0;
  if (l <= tl && tr <= r) {
    long long ans = 0;
    for (int i = 0; i <= 20; i++) {
      ans += (1 << i) * t[v][i];
    }
    return ans;
  }
  int tm = (tl + tr) / 2;
  return sum(v * 2, tl, tm, l, r) + sum(v * 2 + 1, tm + 1, tr, l, r);
}
void upd(int v, int tl, int tr, int l, int r, int val) {
  push(v, tl, tr);
  if (l > r || l > tr || r < tl) return;
  if (l <= tl && tr <= r) {
    p[v] ^= val;
    push(v, tl, tr);
    return;
  }
  int tm = (tl + tr) / 2;
  upd(v * 2, tl, tm, l, r, val);
  upd(v * 2 + 1, tm + 1, tr, l, r, val);
  for (int i = 0; i <= 20; i++) {
    t[v][i] = t[v * 2][i] + t[v * 2 + 1][i];
  }
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  build(1, 1, n);
  int m;
  cin >> m;
  for (int i = 1; i <= m; i++) {
    int t, l, r, first;
    cin >> t >> l >> r;
    if (t == 1) {
      cout << sum(1, 1, n, l, r) << endl;
    } else {
      cin >> first;
      upd(1, 1, n, l, r, first);
    }
  }
}
