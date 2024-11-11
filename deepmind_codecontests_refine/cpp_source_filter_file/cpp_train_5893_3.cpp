#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long MAXN = 1e6 + 5;
const long long INF = 1e9;
const double PI = 3.14159265359;
pair<int, int> t[MAXN], t1[MAXN];
int a[MAXN], n;
void build(int v, int tl, int tr) {
  if (tl == tr) {
    t1[v] = {a[tl], tl};
    t[v] = {a[tl], tl};
    return;
  }
  int tm = (tl + tr) >> 1;
  build(v << 1, tl, tm);
  build(v << 1 | 1, tm + 1, tr);
  if (t1[v << 1].first < t1[v << 1 | 1].first)
    t1[v] = t1[v << 1];
  else
    t1[v] = t[v << 1 | 1];
  if (t[v << 1].first < t[v << 1 | 1].first)
    t[v] = t[v << 1 | 1];
  else
    t[v] = t[v << 1];
}
pair<int, int> get1(int v, int tl, int tr, int l, int r) {
  if (tl > r || tr < l) return {-INF, -INF};
  if (tl >= l && tr <= r) return t[v];
  int tm = (tl + tr) >> 1;
  pair<int, int> x = get1(v << 1, tl, tm, l, r);
  pair<int, int> y = get1(v << 1 | 1, tm + 1, tr, l, r);
  if (x.first > y.first) return x;
  return y;
}
pair<int, int> get(int v, int tl, int tr, int l, int r) {
  if (tl > r || tr < l) return {INF, INF};
  if (tl >= l && tr <= r) return t1[v];
  int tm = (tl + tr) >> 1;
  pair<int, int> x = get(v << 1, tl, tm, l, r);
  pair<int, int> y = get(v << 1 | 1, tm + 1, tr, l, r);
  if (x.first < y.first) return x;
  return y;
}
long long ans, ans1;
void Min(int l, int r) {
  if (l > r) return;
  pair<int, int> pos = get(1, 1, n, l, r);
  ans += (pos.second - l + 1) * 1ll * (r - pos.second + 1) * pos.first;
  Min(l, pos.second - 1);
  Min(pos.second + 1, r);
}
void Max(int l, int r) {
  if (l > r) return;
  pair<int, int> pos = get1(1, 1, n, l, r);
  ans1 += (pos.second - l + 1) * 1ll * (r - pos.second + 1) * pos.first;
  Max(l, pos.second - 1);
  Max(pos.second + 1, r);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  build(1, 1, n);
  Min(1, n);
  Max(1, n);
  cout << abs(ans1 - ans);
}
