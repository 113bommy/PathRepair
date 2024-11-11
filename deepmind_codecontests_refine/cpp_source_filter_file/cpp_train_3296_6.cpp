#include <bits/stdc++.h>
#pragma GCC optimize(3)
using namespace std;
bool Finish_read;
template <class T>
inline void read(T &x) {
  Finish_read = 0;
  x = 0;
  int f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    if (ch == EOF) return;
    ch = getchar();
  }
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  x *= f;
  Finish_read = 1;
}
template <class T>
inline void print(T x) {
  if (x / 10 != 0) print(x / 10);
  putchar(x % 10 + '0');
}
template <class T>
inline void writeln(T x) {
  if (x < 0) putchar('-');
  x = abs(x);
  print(x);
  putchar('\n');
}
template <class T>
inline void write(T x) {
  if (x < 0) putchar('-');
  x = abs(x);
  print(x);
}
int n, d[305], cnt, u[1000006], v[1000006], nowd[1005];
inline void solve(int l, int r, int vl, int vr) {
  if (l > r) return;
  if (l == r) {
    for (int i = vr; i > vr - vl; --i)
      for (int j = vl; j < i; j++)
        cnt++, u[cnt] = i, v[cnt] = j, nowd[i]++, nowd[j]++;
    return;
  }
  int w = d[l];
  for (int i = vr; i > vr - w; --i)
    for (int j = vl; j < i; j++)
      cnt++, u[cnt] = i, v[cnt] = j, nowd[i]++, nowd[j]++;
  int nxtl = vl + d[r] - d[r - 1], nxtr = vr - d[l];
  for (int i = r; i >= l; --i) d[i] -= d[l];
  solve(l + 1, r - 1, nxtl, nxtr);
}
int main() {
  read(n);
  for (int i = 1; i <= n; i++) read(d[i]);
  solve(1, n, 1, d[n] + 1);
  writeln(cnt);
  for (int i = 1; i <= cnt; i++) printf("%d %d\n", u[i], v[i]);
}
