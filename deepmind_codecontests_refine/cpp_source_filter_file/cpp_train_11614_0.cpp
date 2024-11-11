#include <bits/stdc++.h>
using namespace std;
#pragma warning(disable : 4996)
void nop() { int a = 5; };
int n, a, b, u, ma;
int d[20], e[20], f[20];
int st, best, cur;
void out() {
  cout << st + best << endl;
  for (int i = 2; i < n; i++)
    for (int j = 0; j < f[i]; j++) cout << i << " ";
};
void rec(int p) {
  if (p == n) {
    bool b = 1;
    if (cur >= best) return;
    for (int i = 2; i < n; i++)
      if (d[i] >= 0) {
        b = 0;
        break;
      };
    if (b) {
      best = cur;
      for (int i = 2; i < n; i++) f[i] = e[i];
    };
    return;
  };
  rec(p + 1);
  int i;
  for (i = 1;; i++) {
    d[p - 1] -= b;
    d[p] -= a;
    e[p]++;
    d[p + 1] -= a;
    cur++;
    if (d[p - 1] < 0 && d[p] < 0 && d[p + 1] < 0) {
      rec(p + 1);
      break;
    } else
      rec(p + 1);
  };
  cur -= i;
  d[p - 1] += b * i;
  d[p] += a * i;
  e[p] -= i;
  d[p + 1] += a * i;
};
int main() {
  cin >> n >> a >> b;
  for (int i = 1; i <= n; i++) {
    cin >> d[i];
    if (d[i] > ma) ma = d[i];
  };
  if (n == 3) {
    while (d[1] >= 0 || d[2] >= 0 || d[3] >= 0) {
      d[1] -= b;
      d[2] -= a;
      f[2]++;
      d[3] -= b;
      st++;
    };
    out();
    return 0;
  };
  while (d[1] >= 0) {
    d[1] -= b;
    d[2] -= a;
    e[2]++;
    d[3] -= b;
    st++;
  };
  while (d[n] >= 0) {
    d[n - 2] -= b;
    d[n - 1] -= a;
    e[n - 1]++;
    d[n] -= b;
    st++;
  };
  best = 1000000;
  rec(2);
  out();
  return 0;
};
