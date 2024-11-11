#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-9;
const int mod = 1e9 + 7;
const long long INF = 1e18 + 1;
const long long inf = 1e12 + 1;
const int N = 5e5 + 9;
int n, k;
int a, b;
int p[N];
int t1[4 * N];
int t2[4 * N];
inline void update(int v, int l, int r, int pos, int val, int x, int y) {
  if (l == r && l == pos) {
    t1[v] += val;
    t2[v] += val;
    t1[v] = min(y, t1[v]);
    t2[v] = min(x, t2[v]);
    return;
  }
  int md = (l + r) / 2;
  if (pos <= md)
    update(v + v, l, md, pos, val, x, y);
  else
    update(v + v + 1, md + 1, r, pos, val, x, y);
  t1[v] = t1[v + v] + t1[v + v + 1];
  t2[v] = t2[v + v] + t2[v + v + 1];
}
long long sum1(int v, int l, int r, int L, int R) {
  if (L > r || R < l) return 0;
  if (L <= l && r <= R) return t1[v];
  int md = (l + r) / 2;
  return sum1(v + v, l, md, L, R) + sum1(v + v + 1, md + 1, r, L, R);
}
long long sum2(int v, int l, int r, int L, int R) {
  if (L > r || R < l) return 0;
  if (L <= l && r <= R) return t2[v];
  int md = (l + r) / 2;
  return sum2(v + v, l, md, L, R) + sum2(v + v + 1, md + 1, r, L, R);
}
int main() {
  cin >> n >> k >> a >> b;
  int q;
  cin >> q;
  for (int i = 1; i <= q; ++i) {
    int type;
    cin >> type;
    if (type == 1) {
      int d;
      int x;
      cin >> d >> x;
      update(1, 1, n, d, x, a, b);
    } else {
      int ans = 0;
      int d;
      cin >> d;
      if (d > 1) {
        ans += sum1(1, 1, n, 1, d - 1);
      }
      if (d + k <= n) {
        ans += sum2(1, 1, n, d + k, n);
      }
      cout << ans << endl;
    }
  }
  exit(0);
}
