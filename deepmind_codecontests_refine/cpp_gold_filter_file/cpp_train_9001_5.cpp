#include <bits/stdc++.h>
template <typename T>
inline void read(T &x) {
  char c;
  bool neg = false;
  while (!isdigit(c = getchar()) && c != '-')
    ;
  x = 0;
  if (c == '-') {
    neg = true;
    c = getchar();
  }
  do {
    x = x * 10 + c - '0';
  } while (isdigit(c = getchar()));
  if (neg) x = -x;
}
template <typename T>
inline void write(T x) {
  if (x < 0) {
    putchar('-');
    write(-x);
    return;
  }
  if (x < 10) {
    putchar(char(x + 48));
  } else {
    write(x / 10);
    putchar(char(48 + x % 10));
  }
}
template <typename T>
inline void writeln(T x) {
  write(x);
  putchar('\n');
}
using namespace std;
int n, level[2001000], dd[2001000], END[2001000], f[2001000];
long long m, a[2001000];
int cal(int u) {
  int cnt = 0;
  int t = u;
  while (u - t < n) {
    cnt++;
    u = f[u] + 1;
  }
  return cnt;
}
void solve() {
  read(m);
  long long sum = 0;
  int start = 1;
  for (int last = 1; last <= n * 2 - 1; last++) {
    sum += a[last];
    while (sum > m) {
      sum -= a[start];
      f[start] = last - 1;
      start++;
    }
    int len = last - start + 1;
    f[start] = last;
  }
  for (; start < 2 * n; ++start) f[start] = 2 * n - 1;
  start = 1;
  int need = n;
  for (int i = 2; i <= n; i++) {
    if (f[start] - start > f[i] - i) start = i;
  }
  for (int i = start; i <= f[start] + 1; i++) {
    need = min(need, cal(((i - 1) % n) + 1));
  }
  writeln(need);
}
int q;
int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  read(n);
  read(q);
  for (int i = 1; i <= n; i++) read(a[i]);
  for (int i = 1; i <= n; i++) a[i + n] = a[i];
  while (q--) {
    solve();
  }
}
