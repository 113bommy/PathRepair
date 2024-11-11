#include <bits/stdc++.h>
using namespace std;
struct RMQ {
  static const int sz = 262144;
  int t[sz];
  int l[sz];
  int &operator[](int p) { return t[sz / 2 + p]; }
  void build(int n) {
    memset(l, 0, sizeof(l));
    for (int i = (sz / 2 + n); i < (sz); i++) t[i] = 0;
    for (int i = (sz / 2) - 1; i >= 0; i--) t[i] = max(t[2 * i], t[2 * i + 1]);
  }
  void propague(int n) {
    l[2 * n + 1] += l[n];
    l[2 * n] += l[n];
    t[2 * n + 1] += l[n];
    t[2 * n] += l[n];
    l[n] = 0;
  }
  int get(int i, int j, int n = 1, int a = 0, int b = sz / 2) {
    if (j <= a || i >= b) return 0;
    if (i <= a && b <= j) return t[n];
    propague(n);
    int c = (a + b) / 2;
    return get(i, j, 2 * n, a, c) + get(i, j, 2 * n + 1, c, b);
  }
  void setrange(int i, int j, int val, int n = 1, int a = 0, int b = sz / 2) {
    if (j <= a || i >= b) return;
    if (i <= a && b <= j) {
      t[n] += val;
      l[n] += val;
      return;
    }
    int c = (a + b) / 2;
    propague(n);
    setrange(i, j, val, 2 * n, a, c);
    setrange(i, j, val, 2 * n + 1, c, b);
  }
} rmq;
int n, m, w;
int a[100100];
bool solve(int h) {
  for (int i = (0); i < (n); i++) rmq[i] = a[i];
  rmq.build(n);
  int c = 0;
  for (int p = (0); p < (n); p++) {
    int hf = rmq.get(p, p + 1);
    if (hf < h) {
      rmq.setrange(p, p + w, h - hf);
      c += (h - hf);
      if (c > m) return false;
    }
  }
  return true;
}
int main() {
  cin >> n >> m >> w;
  for (int i = (0); i < (n); i++) cin >> a[i];
  int a = 1, b = 1000100000;
  if (solve(b))
    cout << b << endl;
  else {
    while (b - a > 1) {
      int c = (a + b) / 2;
      if (solve(c))
        a = c;
      else
        b = c;
    }
    cout << a << endl;
  }
  return 0;
}
