#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 2e9;
const long long INF64 = 9e18;
const long double EPS = 1e-9;
const long double PI = 3.14159265358979310000;
const int N = 810000;
const int M = 104600;
int n, k, a, m;
struct tree {
  int t[N];
  tree() {
    for (int i = 0; i < int(N); i++) t[i] = 0;
  }
  void update(int v, int tl, int tr, int num) {
    if (tl == tr)
      t[v] = 1;
    else {
      int tm = (tl + tr) / 2;
      if (num <= tm)
        update(v * 2, tl, tm, num);
      else
        update(v * 2 + 1, tm + 1, tr, num);
      t[v] = t[v * 2] + t[v * 2 + 1];
    }
  }
  int sum(int v, int tl, int tr, int l, int r) {
    if (l > r) return 0;
    if (tl == l && tr == r) return t[v];
    int tm = (tl + tr) / 2;
    return sum(v * 2, tl, tm, l, min(r, tm)) +
           sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
  }
  int left(int v, int tl, int tr, int num) {
    if (tl == tr) return tl;
    int tm = (tl + tr) / 2;
    if (sum(1, 0, n + 1, tm + 1, num) > 0)
      return left(v * 2 + 1, tm + 1, tr, num);
    else
      return left(v * 2, tl, tm, num);
  }
  int right(int v, int tl, int tr, int num) {
    if (tl == tr) return tl;
    int tm = (tl + tr) / 2;
    if (sum(1, 0, n + 1, num, tm) > 0)
      return right(v * 2, tl, tm, num);
    else
      return right(v * 2 + 1, tm + 1, tr, num);
  }
} t;
int check(int first) {
  int l, r, m;
  l = 0;
  r = n / a + 10;
  while (r - l > 1) {
    m = (l + r) / 2;
    if (a * m + m - 1 <= first)
      l = m;
    else
      r = m;
  }
  if (a * r + r - 1 <= first)
    return r;
  else
    return l;
}
int main() {
  int sum, first, second, w, tt = -1;
  cin >> n >> k >> a;
  n++;
  t.update(1, 0, n, 0);
  t.update(1, 0, n, n);
  cin >> m;
  sum = check(n - 1);
  for (int u = 0; u < int(m); u++) {
    scanf("%d", &w);
    first = t.left(1, 0, n, w - 1);
    second = t.right(1, 0, n, w + 1);
    sum -= check(second - first - 1);
    t.update(1, 0, n, w);
    sum += check(w - first - 1) + check(second - w - 1);
    if (sum < k) {
      if (tt == -1) tt = u + 1;
    }
  }
  cout << tt;
  return 0;
}
