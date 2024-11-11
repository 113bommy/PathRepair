#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 29;
const long long LINF = 1LL << 60;
long long mod = 1e9 + 7;
char READ_DATA;
int SIGNAL_INPUT;
template <typename Type>
inline Type ru(Type &v) {
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
  return v;
}
inline long long modru(long long &v) {
  long long p = 0;
  SIGNAL_INPUT = 1;
  while ((READ_DATA = getchar()) < '0' || READ_DATA > '9')
    if (READ_DATA == '-')
      SIGNAL_INPUT = -1;
    else if (READ_DATA == EOF)
      return EOF;
  p = v = READ_DATA - '0';
  while ((READ_DATA = getchar()) >= '0' && READ_DATA <= '9') {
    v = (v * 10 + READ_DATA - '0') % mod;
    p = (p * 10 + READ_DATA - '0') % (mod - 1);
  }
  v *= SIGNAL_INPUT;
  return p;
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
  Edge(int _u = 0, int _v = 0, int nxt = -1, long long _w = 1,
       long long _cap = 0) {
    u = _u;
    v = _v;
    w = _w;
    cap = _cap;
    flow = 0;
    next = nxt;
  }
  int operator<(const Edge &b) const { return w < b.w; }
};
const int maxn = 3e5 + 7;
double eps = 1e-6;
int n, c, d;
pair<int, int> a[maxn], b[maxn];
int n1, n2, ans;
int pre[maxn];
void solve(pair<int, int> *a, int n, int up) {
  memset(pre, 0, sizeof(pre));
  for (int i = 1; i <= n; ++i)
    pre[i] = max(pre[i], max(pre[i - 1], a[i].second));
  int l, r, mid;
  for (int i = 1; i <= n; ++i) {
    l = 0;
    r = i - 1;
    while (l < r) {
      mid = (l + r >> 1) + 1;
      if (a[mid].first + a[i].first <= up)
        l = mid;
      else
        r = mid - 1;
    }
    if (r) ans = max(ans, a[i].second + a[r].second);
  }
}
int main() {
  int B, P;
  char ch[10];
  ru(n, c, d);
  int amaxd = -INF, bmaxd = -INF;
  while (n--) {
    ru(B, P);
    scanf("%s", ch);
    if (ch[0] == 'C') {
      a[++n1] = pair<int, int>(P, B);
      if (P <= c) amaxd = max(amaxd, B);
    } else {
      b[++n2] = pair<int, int>(P, B);
      if (P <= d) bmaxd = max(bmaxd, B);
    }
  }
  ans = max(ans, amaxd + bmaxd);
  sort(a + 1, a + n1 + 1);
  sort(b + 1, b + n2 + 1);
  solve(a, n1, c);
  solve(b, n2, d);
  cout << ans;
}
