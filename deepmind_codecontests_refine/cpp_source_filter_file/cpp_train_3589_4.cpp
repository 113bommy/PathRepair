#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 7;
const long long inf = 0x3f3f3f3f3f3f3f;
int n, m, d, B, G, b[MAXN], g[MAXN];
vector<int> a[MAXN << 1], f[MAXN << 1];
long long ans = 1;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int exgcd(int a, int b, int &x, int &y, int d = 0) {
  return b ? (d = exgcd(b, a % b, y, x), y -= a / b * x, d) : (x = 1, y = 0, a);
}
namespace fastIO {
static char buf[(1 << 19)], *p1 = buf + (1 << 19), *pend = buf + (1 << 19);
inline char nc() {
  if (p1 == pend) {
    p1 = buf;
    pend = buf + fread(buf, 1, (1 << 19), stdin);
  }
  return *p1++;
}
inline int read() {
  int x = 0, f = 1;
  register char s = nc();
  for (; !isdigit(s); s = nc())
    if (s == '-') f = -1;
  for (; isdigit(s); s = nc()) x = (x << 1) + (x << 3) + s - '0';
  return x * f;
}
}  // namespace fastIO
using namespace fastIO;
inline long long solve(vector<int> a, vector<int> b) {
  vector<int> s = a;
  for (unsigned int i = 0; i < b.size(); ++i) s.push_back(b[i]);
  sort(s.begin(), s.end());
  int k = unique(s.begin(), s.end()) - s.begin(), x, y;
  if (n == k) {
    int c[m];
    memset(c, 0, sizeof(c));
    for (unsigned int i = 0; i < a.size(); ++i)
      if (a[i] < m) ++c[a[i]];
    for (unsigned int i = 0; i < b.size(); ++i)
      if (b[i] < m) ++c[b[i]];
    for (int i = m - 1; ~i; --i)
      if (c[i] == 1) return i;
    return -1;
  }
  vector<pair<int, long long> > e[2 * k + 1];
  for (int i = 0; i < k; ++i)
    e[2 * k].push_back(make_pair(i, s[i])), e[i + k].push_back(make_pair(i, m));
  exgcd(m, n, x, y);
  x = (x % n + n) % n;
  pair<int, int> p[k];
  for (int i = 0; i < k; ++i) p[i] = make_pair(1ll * x * (s[i] - s[0]) % n, i);
  sort(p, p + k);
  for (int i = 0, j = 1 % k; i < k; ++i, j = (++j == k) ? 0 : j)
    e[p[i].second].push_back(make_pair(
        p[j].second + k,
        1ll * m *
            (p[j].first - p[i].first - 1 < 0 ? p[j].first - p[i].first - 1 + n
                                             : p[j].first - p[i].first - 1)));
  map<int, int> h;
  for (int i = 0; i < k; ++i) h[s[i]] = i;
  for (int i = 0; i < k; ++i) {
    if (h.find((s[i] + m) % n) != h.end()) {
      int j = h[(s[i] + m) % n];
      e[i].push_back(make_pair(j + k, 0)), e[j + k].push_back(make_pair(i, 0));
    }
  }
  priority_queue<pair<long long, int> > q;
  int v[2 * k + 1];
  long long d[2 * k + 1], now = 0;
  memset(v, 0, sizeof(v));
  memset(d, 0x3f, sizeof(d));
  q.push(make_pair(0, 2 * k)), d[2 * k] = 0;
  while (!q.empty()) {
    int x = q.top().second;
    q.pop();
    if (v[x]) continue;
    v[x] = 1;
    now = max(now, d[x]);
    for (unsigned int i = 0; i < e[x].size(); ++i) {
      int v = e[x][i].first;
      long long z = e[x][i].second;
      if ((d[v] > d[x] + z)) d[v] = d[x] + z, q.push(make_pair(-d[v], v));
    }
  }
  return now;
}
int main() {
  n = read();
  m = read();
  B = read();
  for (int i = 1; i <= B; ++i) b[i] = read();
  G = read();
  for (int i = 1; i <= G; ++i) g[i] = read();
  if (n < m) swap(n, m), swap(B, G), swap(b, g);
  if ((d = gcd(n, m)) > (B + G)) return puts("-1"), 0;
  n /= d;
  m /= d;
  for (int i = 1; i <= B; ++i) a[b[i] % d].push_back(b[i] / d);
  for (int i = 1; i <= G; ++i) f[g[i] % d].push_back(g[i] / d);
  for (int i = 0; i < d; ++i)
    if (!a[i].size() && !f[i].size()) return puts("-1"), 0;
  for (int i = 0; i < d; ++i) ans = max(ans, solve(a[i], f[i]) * d + i);
  printf("%lld\n", ans);
  return 0;
}
