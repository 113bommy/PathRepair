#include <bits/stdc++.h>
using namespace std;
char READ_DATA;
int SIGNAL_INPUT;
template <typename Type>
inline char ru(Type &v) {
  SIGNAL_INPUT = 1;
  while ((READ_DATA = getchar()) < '0' || READ_DATA > '9')
    if (READ_DATA == '-')
      SIGNAL_INPUT = -1;
    else if (READ_DATA == EOF)
      return EOF;
  v = READ_DATA - '0';
  while ((READ_DATA = getchar()) >= '0' && READ_DATA <= '9')
    v = v * 10 + READ_DATA - '0';
  v *= SIGNAL_INPUT;
  return 1;
}
template <typename A, typename B>
inline char ru(A &x, B &y) {
  if (ru(x) == EOF) return EOF;
  ru(y);
  return 2;
}
template <typename A, typename B, typename C>
inline char ru(A &x, B &y, C &z) {
  if (ru(x) == EOF) return EOF;
  ru(y);
  ru(z);
  return 3;
}
template <typename A, typename B, typename C, typename D>
inline char ru(A &x, B &y, C &z, D &w) {
  if (ru(x) == EOF) return EOF;
  ru(y);
  ru(z);
  ru(w);
  return 4;
}
struct Edge {
  int u, v, next;
  int w, cap, flow;
  Edge(int _u = 0, int _v = 0, int nxt = -1, int _w = 1, int _cap = 0) {
    u = _u;
    v = _v;
    w = _w;
    cap = _cap;
    flow = 0;
    next = nxt;
  }
};
const int mod = 1e9 + 7;
const int maxn = 2e6 + 2;
int n, k, a[maxn], cnt[maxn], s[maxn * 2], mind = (1 << 28), maxd = 0;
int main() {
  ru(n, k);
  for (int i = 1; i <= n; ++i) {
    ru(a[i]);
    ++cnt[a[i]];
    mind = min(mind, a[i]);
    maxd = max(maxd, a[i]);
  }
  if (mind <= k + 1) {
    printf("%d", mind);
    return 0;
  }
  for (int i = 1; i <= maxn - 2; ++i) s[i] = s[i - 1] + cnt[i];
  int ans = k + 1, tot;
  for (int i = k + 2; i <= mind; ++i) {
    tot = 0;
    for (int j = 1; j * i <= maxd; ++j) {
      tot += s[j * i + k] - s[j * i - 1];
    }
    if (tot == n) ans = i;
  }
  printf("%d", ans);
}
