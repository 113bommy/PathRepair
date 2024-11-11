#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void read(T &x) {
  int ch = 0, f = 0;
  x = 0;
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') f = 1;
  for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - 48;
  if (f) x = -x;
}
const long long N = 100005;
char s[N];
long long n, vis[N], id[N];
struct P {
  long long x, y;
  friend P operator+(P A, P B) { return (P){A.x + B.x, A.y + B.y}; }
  friend P operator-(P A, P B) { return (P){A.x - B.x, A.y - B.y}; }
  friend long long operator*(P A, P B) { return A.x * B.y - B.x * A.y; }
} a[N];
inline bool cmp(long long x, long long y) {
  a[x].y != a[y].y ? a[x].y < a[y].y : a[x].x < a[y].x;
}
signed main() {
  read(n);
  for (long long i = 1; i <= n; i++) read(a[i].x), read(a[i].y);
  for (long long i = 1; i <= n; i++) id[i] = i;
  sort(id + 1, id + n + 1, cmp);
  scanf("%s", s);
  printf("%d ", id[1]), vis[id[1]] = 1;
  P last = a[id[1]];
  for (long long i = 0; i < n - 2; i++) {
    long long now = 0;
    if (s[i] == 'L')
      for (long long j = 1; j <= n; j++)
        if (!vis[id[j]] && (!now || (a[now] - last) * (a[id[j]] - a[now]) > 0))
          now = id[j];
    if (s[i] == 'R')
      for (long long j = 1; j <= n; j++)
        if (!vis[id[j]] && (!now || (a[now] - last) * (a[id[j]] - a[now]) < 0))
          now = id[j];
    printf("%d ", now), vis[now] = 1, last = a[now];
  }
  for (long long i = 1; i <= n; i++)
    if (!vis[i]) printf("%d\n", i);
  return 0;
}
