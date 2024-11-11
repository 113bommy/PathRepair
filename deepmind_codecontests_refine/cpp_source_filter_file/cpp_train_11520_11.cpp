#include <bits/stdc++.h>
void Open() {
  freopen(
      "txt"
      ".in",
      "r", stdin);
  freopen(
      "txt"
      ".out",
      "w", stdout);
}
void Close() {
  fclose(stdin);
  fclose(stdout);
}
using namespace std;
int Read() {
  int val = 0, opt = 1;
  char ch;
  while (!isdigit(ch = getchar()))
    if (ch == '-') opt = -1;
  while (isdigit(ch)) (val *= 10) += ch - '0', ch = getchar();
  return val * opt;
}
int Sum[100100], n, f[100100], q[100100], a[100100], m, p[100100], Ans, tp;
void add(int p, int v) {
  for (; p <= m; p += p & (-p)) Sum[p] += v;
}
int Find(int p) {
  int sum = 0;
  for (; p > 0; p -= p & (-p)) sum += Sum[p];
  return sum;
}
void work() {
  n = Read(), m = Read();
  for (int i = 1; i <= n; i++) {
    add(Read(), 1);
    add(Read() + 1, -1);
  }
  for (int i = 1; i <= m; i++) a[i] = Find(i);
  memset(p, 0x7f, sizeof p);
  p[0] = 0;
  f[0] = 0;
  int t, tp = 0;
  for (int i = 1; i <= m; i++) {
    t = upper_bound(p, p + tp, a[i]) - p;
    if (a[i] >= p[t]) {
      f[i] = t + 1;
      p[t + 1] = a[i];
      tp++;
    } else {
      f[i] = t;
      p[t] = a[i];
    }
  }
  memset(p, 0x7f, sizeof p);
  p[0] = 0;
  f[0] = 0;
  tp = 0;
  for (int i = m; i; i--) {
    t = upper_bound(p, p + tp, a[i]) - p;
    if (a[i] >= p[t]) {
      q[i] = t + 1;
      q[t + 1] = a[i];
      tp++;
    } else {
      q[i] = t;
      p[t] = a[i];
    }
  }
  for (int i = 1; i <= m; i++) Ans = max(Ans, f[i] + q[i + 1]);
  printf("%d", Ans);
}
int main(void) {
  work();
  return 0;
}
