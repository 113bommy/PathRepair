#include <bits/stdc++.h>
#pragma GCC optimize(3, "Ofast", "inline")
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
int q, n, tot;
long long k, pw[105];
inline void prework() {
  tot = 31;
  for (int i = 1; i <= tot; ++i) pw[i] = 4 * pw[i - 1] + 1;
}
inline void Y(long long x) { printf("YES %lld\n", x); }
inline void N() { puts("NO"); }
int main() {
  prework(), read(q);
  while (q--) {
    read(n), read(k);
    if (n > tot || pw[n - 1] >= k - 1) {
      Y(n - 1);
      continue;
    }
    if (k > pw[n]) {
      N();
      continue;
    }
    int ans = -1;
    for (int i = 0; i < n - 1; ++i) {
      if ((1ll << (n - i + 1)) - 2 - n + i > k) continue;
      if (pw[n] - pw[i] * ((1ll << (n - i + 1)) - 1) < k) continue;
      ans = i;
      break;
    }
    ans == -1 ? Y(ans) : N();
  }
}
