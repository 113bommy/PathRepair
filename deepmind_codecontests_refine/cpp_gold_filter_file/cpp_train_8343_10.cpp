#include <bits/stdc++.h>
using namespace std;
int countbit(int n) { return (n == 0) ? 0 : (1 + countbit(n & (n - 1))); }
int lowbit(int n) { return (n ^ (n - 1)) & n; }
const double pi = acos(-1.0);
const double eps = 1e-11;
template <class T>
T sqr(T x) {
  return x * x;
}
template <class T>
void checkmin(T &a, T b) {
  if (b < a) a = b;
}
template <class T>
void checkmax(T &a, T b) {
  if (b > a) a = b;
}
const long long oo = 100000000LL * 100000000LL;
const int maxn = 200000 + 5;
const int maxsize = 2 << 20;
int n, m, c[maxn];
pair<pair<int, int>, int> d[maxn];
long long delta[maxsize], best[maxsize];
void update(int v) {
  if (delta[v] == 0) return;
  long long d = delta[v];
  delta[v * 2 + 1] += d;
  best[v * 2 + 1] += d;
  delta[v * 2 + 2] += d;
  best[v * 2 + 2] += d;
  delta[v] = 0;
}
void update1(int v, int s, int t, int gs, int gt, long long d) {
  if (s >= gs && t <= gt) {
    delta[v] += d;
    best[v] += d;
    return;
  }
  update(v);
  int m = s + (t - s) / 2;
  if (m >= gs) update1(v * 2 + 1, s, m, gs, gt, d);
  if (m < gt) update1(v * 2 + 2, m + 1, t, gs, gt, d);
  best[v] = max(best[v * 2 + 1], best[v * 2 + 2]) + delta[v];
}
void update2(int v, int s, int t, int key, long long d) {
  if (s == t) {
    delta[v] = best[v] = d;
    return;
  }
  update(v);
  int m = s + (t - s) / 2;
  if (key <= m)
    update2(v * 2 + 1, s, m, key, d);
  else
    update2(v * 2 + 2, m + 1, t, key, d);
  best[v] = max(best[v * 2 + 1], best[v * 2 + 2]) + delta[v];
}
long long query(int v, int s, int t, int gs, int gt) {
  if (s >= gs && t <= gt) return best[v];
  update(v);
  int m = s + (t - s) / 2;
  long long ret = -oo;
  if (m >= gs) checkmax(ret, query(v * 2 + 1, s, m, gs, gt));
  if (m < gt) checkmax(ret, query(v * 2 + 2, m + 1, t, gs, gt));
  return ret;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
  for (int i = 0; i < m; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    d[i] = make_pair(make_pair(b, a), c);
  }
  sort(d, d + m);
  memset(delta, 0, sizeof(delta));
  memset(best, 0, sizeof(best));
  update1(0, 0, n, 1, n, -oo);
  for (int k = 0, i = 1; i <= n; i++) {
    long long key = query(0, 0, n, 0, i - 1);
    update1(0, 0, n, 0, i - 1, -c[i]);
    update2(0, 0, n, i, key);
    for (; k < m && d[k].first.first == i; k++)
      update1(0, 0, n, 0, d[k].first.second - 1, d[k].second);
  }
  long long R = query(0, 0, n, 0, n);
  cout << R << endl;
  return 0;
}
