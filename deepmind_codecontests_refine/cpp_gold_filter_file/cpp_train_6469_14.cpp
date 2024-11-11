#include <bits/stdc++.h>
using namespace std;
const double pi = 3.14159265358979323846;
#pragma GCC optimize("-O2")
template <class T>
using min_heap = priority_queue<T, std::vector<T>, std::greater<T> >;
const int LM = 1e5;
const int INF = 2e9;
int n, q, sz = 1;
long long a[LM + 2], b[LM + 2], k[LM + 2], p[LM + 2], dp[LM + 2];
long long seg[4 * LM + 3], flag[4 * LM + 3], val[4 * LM + 3];
void pre() {
  for (int i = 1; i <= n - 1; i++) {
    p[i] = p[i - 1] + k[i];
  }
  for (int i = 1; i <= n - 1; i++) {
    dp[i] = dp[i - 1] + p[i];
  }
  for (int i = 1; i <= n; i++) {
    b[i] = a[i] - p[i - 1];
  }
}
void build(long long seg[], long long b[]) {
  while (sz < n) {
    sz *= 2;
  }
  for (int i = 1; i <= n; i++) {
    seg[i + sz - 1] = b[i];
  }
  for (int i = sz - 1; i >= 1; i--) {
    seg[i] = seg[2 * i] + seg[2 * i + 1];
  }
}
void lazy(int x, int lb, int rb) {
  if (flag[x]) {
    flag[2 * x] = 1;
    val[2 * x] = val[x];
    flag[2 * x + 1] = 1;
    val[2 * x + 1] = val[x];
    seg[2 * x] = ((rb - lb + 1) / 2) * val[2 * x];
    seg[2 * x + 1] = ((rb - lb + 1) / 2) * val[2 * x + 1];
    flag[x] = 0;
  }
}
long long sum(int x, int lb, int rb, int a, int b) {
  if (!(a <= b and lb <= a <= rb and lb <= b <= rb)) {
    return 0;
  }
  if (a == lb and b == rb) {
    return seg[x];
  }
  int mid = (lb + rb) / 2;
  if (b <= mid) {
    lazy(x, lb, rb);
    return sum(2 * x, lb, mid, a, b);
  }
  if (a >= mid + 1) {
    lazy(x, lb, rb);
    return sum(2 * x + 1, mid + 1, rb, a, b);
  }
  lazy(x, lb, rb);
  return sum(2 * x, lb, mid, a, mid) + sum(2 * x + 1, mid + 1, rb, mid + 1, b);
}
void range_update(int x, int lb, int rb, int a, int b, long long value) {
  if (!(a <= b and lb <= a <= rb and lb <= b <= rb)) {
    return;
  }
  if (lb == a and rb == b) {
    flag[x] = 1;
    val[x] = value;
    seg[x] = (rb - lb + 1) * value;
    return;
  }
  int mid = (lb + rb) / 2;
  if (b <= mid) {
    lazy(x, lb, rb);
    range_update(2 * x, lb, mid, a, b, value);
  } else if (a >= mid + 1) {
    lazy(x, lb, rb);
    range_update(2 * x + 1, mid + 1, rb, a, b, value);
  } else {
    lazy(x, lb, rb);
    range_update(2 * x, lb, mid, a, mid, value);
    range_update(2 * x + 1, mid + 1, rb, mid + 1, b, value);
  }
  seg[x] = seg[2 * x] + seg[2 * x + 1];
}
long long at(int i) { return sum(1, 1, sz, i, i); }
int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n - 1; i++) cin >> k[i];
  pre();
  build(seg, b);
  cin >> q;
  while (q--) {
    char c;
    cin >> c;
    if (c == '+') {
      int i, x;
      cin >> i >> x;
      range_update(1, 1, sz, i, i, at(i) + x);
      long long to = at(i);
      if (i == n) continue;
      if (at(n) < to) {
        range_update(1, 1, sz, i + 1, n, to);
      } else {
        int l = i + 1, r = n;
        for (int i = 1; i <= 30; i++) {
          int mid = (l + r) / 2;
          if (at(mid) >= to) {
            r = mid;
          } else {
            l = mid + 1;
          }
        }
        if (i + 2 <= l <= n) range_update(1, 1, sz, i + 1, l - 1, to);
      }
    } else {
      int l, r;
      cin >> l >> r;
      long long t = sum(1, 1, sz, l, r);
      cout << t + dp[r - 1] - dp[max(l - 2, 0)] << endl;
    }
  }
}
