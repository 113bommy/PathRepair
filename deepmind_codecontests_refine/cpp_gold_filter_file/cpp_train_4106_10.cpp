#include <bits/stdc++.h>
using namespace std;
const int inf = ~0U >> 1;
const long long INF = (long long)1e18;
const double pi = acos(-1.0);
template <class T>
inline void read(T &n) {
  char c;
  for (c = getchar(); !(c >= '0' && c <= '9'); c = getchar())
    ;
  n = c - '0';
  for (c = getchar(); c >= '0' && c <= '9'; c = getchar()) n = n * 10 + c - '0';
}
int pw(int base, int n, int mo) {
  if (n == 0) return 1;
  if (n == 1) return base;
  int tmp = pw(base, n >> 1, mo);
  tmp = (long long)tmp * tmp % mo;
  if (n & 1) tmp = (long long)tmp * base % mo;
  return tmp;
}
struct point {
  int x, y;
  point() {}
  point(int _x, int _y) : x(_x), y(_y) {}
};
struct edge {
  int y;
  edge *nxt;
  edge(int _y, edge *_nxt) : y(_y), nxt(_nxt) {}
};
const int maxn = 200000;
struct seq {
  int s, f;
} a[maxn];
int N, M, best, sum[maxn][2];
long long ans;
bool cmp(const seq &a, const seq &b) {
  return (a.f < b.f) || (a.f == b.f && a.s < b.s);
}
void upd(int _best, long long _ans) {
  if (_best > best && _ans)
    best = _best, ans = _ans;
  else if (_best == best)
    ans += _ans;
}
long long C(int N, int M) {
  if (M == 2)
    return (long long)N * (N - 1) / 2;
  else if (M == 3)
    return (long long)N * (N - 1) * (N - 2) / 6;
}
void solve() {
  sort(a + 1, a + N + 1, cmp);
  for (int i = (1); i <= (N); ++i)
    sum[i][a[i].s] = sum[i - 1][a[i].s] + 1,
    sum[i][1 - a[i].s] = sum[i - 1][1 - a[i].s];
  int Min = inf, Max = -inf;
  for (int i = (1); i <= (N); ++i)
    if (a[i].s == 0) {
      Max = max(Max, a[i].f);
      Min = min(Min, a[i].f);
    }
  int t1 = 0, t2 = 0;
  for (int i = (1); i <= (N); ++i)
    if (a[i].s == 0) {
      if (a[i].f == Min) t1++;
      if (a[i].f == Max) t2++;
    }
  ans = best = 0;
  if (Min != Max) {
    ans = C(sum[N][0], 3) - C(sum[N][0] - t2, 3) - C(sum[N][0] - t1, 3) +
          C(sum[N][0] - t1 - t2, 3);
  } else {
    ans = C(t1, 3);
  }
  if (ans) best = 2 * (Max - Min);
  if (sum[N][0] >= 2 && sum[N][1] > 0) {
    int clo = 0, cnt = 0;
    for (int i = (1); i <= (N); ++i)
      if (a[i].s == 1) {
        if (a[i].f > clo)
          clo = a[i].f, cnt = 1;
        else if (a[i].f == clo)
          cnt++;
      } else {
        upd(2 * M - 2 * (a[i].f - clo),
            (long long)(sum[N][0] - sum[i][0]) * cnt);
      }
  }
  long long t = 0;
  for (int i = (1); i <= (N); ++i)
    if (a[i].s == 1) t += (long long)sum[i][0] * (sum[N][0] - sum[i][0]);
  if (t) {
    upd(2 * M, t);
  }
  if (sum[N][0] >= 2 && sum[N][1] > 0) {
    int clo = 0, cnt = 0;
    for (int i = (1); i <= (N); ++i)
      if (a[i].s == 0) {
        if (a[i].f > clo)
          clo = a[i].f, cnt = 1;
        else if (a[i].f == clo)
          cnt++;
      } else {
        upd(2 * M - 2 * (a[i].f - clo),
            C(sum[i][0], 2) - C(sum[i][0] - cnt, 2));
      }
  }
}
int main() {
  scanf("%d%d", &M, &N);
  for (int i = (1); i <= (N); ++i) scanf("%d%d", &a[i].s, &a[i].f);
  solve();
  int Best = best;
  long long Ans = ans;
  for (int i = (1); i <= (N); ++i) a[i].s = 1 - a[i].s, a[i].f = M - a[i].f;
  solve();
  if (best > Best)
    Best = best, Ans = ans;
  else if (best == Best)
    Ans += ans;
  printf("%lld\n", Ans);
  return 0;
}
