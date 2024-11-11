#include <bits/stdc++.h>
using namespace std;
inline int icin() {
  char c = getchar();
  int s = 0;
  bool sign = 0;
  while (!isdigit(c) && c ^ '-') c = getchar();
  if (c == '-') sign = 1, c = getchar();
  while (isdigit(c)) s = (s << 1) + (s << 3) + c - '0', c = getchar();
  return sign ? -s : s;
}
int c[100009 * 31][2], C, sz[100009 * 31];
inline void Insert(int x) {
  int now = 1;
  sz[1]++;
  for (register int i = 30; ~i; i--) {
    int t = x >> i & 1;
    if (!c[now][t]) c[now][t] = ++C;
    now = c[now][t];
    sz[now]++;
  }
}
int n, a[100009];
int main() {
  int T = icin();
  while (T--) {
    int n = icin();
    C = 1;
    for (register int i = 1; i <= (n); ++i) a[i] = icin();
    long long ans = 0;
    for (register int i = 1; i <= n; ++i) {
      int now = 1, dep = 30;
      while (~a[i] >> dep & 1) now = c[now][0], dep--;
      ans += sz[c[now][1]];
      Insert(a[i]);
    }
    cout << ans << '\n';
    while (C) sz[C] = c[C][0] = c[C][1] = 0, C--;
  }
}
