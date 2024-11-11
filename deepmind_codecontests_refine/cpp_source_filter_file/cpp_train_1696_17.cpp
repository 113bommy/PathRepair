#include <bits/stdc++.h>
using namespace std;
template <class T>
void read(T &x) {
  int f = 0;
  x = 0;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
  for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
  if (f) x = -x;
}
const int next_x[8] = {0, 1, -1, 0, 1, 1, -1, -1};
const int next_y[8] = {1, 0, 0, -1, 1, -1, -1, 1};
const int inf = 1e8 + 5;
const long long linf = 1e18 + 5;
const double PI = acos(-1.0);
const int MAXN = 2e5 + 5;
const int N = 2e5 + 5;
const int M = 1;
const long double eps = 1e-8;
int c[N];
inline void update(int x, int f) {
  for (int i = x; i < N; i += (i & -i)) c[i] += f;
}
inline int sum(int x, int s = 0) {
  for (int i = x; i; i -= (i & -i)) s += c[i];
  return s;
}
inline int query(int l, int r) { return l > r ? 0 : (sum(r) - sum(l - 1)); }
int n;
long long k;
struct point {
  long double x, y, dis, a;
} p[MAXN];
pair<long double, long double> ang[MAXN];
pair<int, int> seg[MAXN];
vector<long double> X;
long double fix(long double x) {
  while (x > PI) x -= 2 * PI;
  while (x < -PI) x += 2 * PI;
  return x;
}
int work() {
  cin >> n >> k;
  for (int i = (1), I = (n) + 1; i < I; ++i) {
    cin >> p[i].x >> p[i].y;
    p[i].dis = sqrt(p[i].x * p[i].x + p[i].y * p[i].y);
    p[i].a = atan2(p[i].y, p[i].x);
  }
  long double l = 0, r = 1e18;
  int cnt = 50;
  while (cnt--) {
    X.clear(), memset(c, 0, sizeof(c));
    const long double m = (l + r) / 2.0;
    int q = 0;
    long long num = 0;
    for (int i = (1), I = (n) + 1; i < I; ++i)
      if (p[i].dis > m) {
        long double a = acos(m / p[i].dis), a1 = fix(p[i].a + a) + PI,
                    a2 = fix(p[i].a - a) + PI;
        if (a1 > a2) swap(a1, a2);
        ang[++q] = {a1, a2}, X.push_back(a1), X.push_back(a2);
      }
    if (q) {
      sort(X.begin(), X.end()), X.erase(unique(X.begin(), X.end()), X.end());
      for (int i = (1), I = (q) + 1; i < I; ++i) {
        seg[i].first =
            lower_bound(X.begin(), X.end(), ang[i].first) - X.begin() + 1;
        seg[i].second =
            lower_bound(X.begin(), X.end(), ang[i].second) - X.begin() + 1;
      }
      sort(seg + 1, seg + 1 + q, [](pair<int, int> a, pair<int, int> b) {
        return a.first < b.first;
      });
      for (int i = (1), I = (q) + 1; i < I; ++i)
        num += query(seg[i].first, seg[i].second - 1), update(seg[i].second, 1);
    }
    long long rank = 1LL * n * (n - 1) / 2 - num;
    if (rank >= k)
      r = m;
    else
      l = m;
  }
  return printf("%.12f\n", double(l));
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  work();
  return 0;
}
