#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
bool fl[N];
long long a, b, sum, ans, dis[N];
map<int, int> ft;
int n, m, k, t, res, f[N], g[N], h[N], q[N];
vector<int> va[N], vb[N], vc[N];
vector<long long> vw[N];
struct node {
  int f, g;
} e[N];
inline int read() {
  int num = 0;
  char g = getchar();
  while (g < 48 || 57 < g) g = getchar();
  while (47 < g && g < 58)
    num = (num << 1) + (num << 3) + g - 48, g = getchar();
  return num;
}
inline int gcd(int a, int b) {
  if (!b) return a;
  return gcd(b, a % b);
}
inline void delit() {
  for (int i = 0; i <= max(f[0], g[0]); i++) swap(f[i], g[i]);
}
inline void exgcd(int x, int y) {
  if (x == 1 && y == 0) {
    a = 1, b = 0, sum = 1;
    return;
  }
  exgcd(y, x % y);
  long long fa = b, fb = a - (x / y) * b;
  swap(a, fa), swap(b, fb), sum = a;
}
inline int fceil(int x, int k) {
  if (x % k) return x / k + 1;
  return x / k;
}
inline bool cmp(node a, node b) { return a.g < b.g; }
int main() {
  n = read(), m = read(), k = gcd(n, m), ans = 1;
  f[0] = read();
  for (int i = 1; i <= f[0]; i++) f[i] = read() + 1, ft[f[i]]++;
  g[0] = read();
  for (int i = 1; i <= g[0]; i++) g[i] = read() + 1, ft[f[i]]++;
  for (int i = 1; i <= f[0]; i++)
    if (ft[f[i]] != 2 && f[i] <= min(n, m)) ans = max(ans, 1ll * f[i]);
  for (int i = 1; i <= g[0]; i++)
    if (ft[g[i]] != 2 && g[i] <= min(n, m)) ans = max(ans, 1ll * g[i]);
  if (k > 1e6) {
    puts("-1");
    return 0;
  }
  if (n < m) delit(), swap(n, m);
  for (int i = 1; i <= f[0]; i++)
    fl[f[i] % k] = 1, va[f[i] % k].push_back(f[i]);
  for (int i = 1; i <= g[0]; i++)
    fl[g[i] % k] = 1, vb[g[i] % k].push_back(g[i]);
  for (int i = 0; i < k; i++)
    if (!fl[i]) {
      puts("-1");
      return 0;
    }
  for (int i = 0; i < k; i++) {
    int la = va[i].size(), lb = vb[i].size();
    h[0] = 0, q[0] = 0;
    int a = n / k, b = m / k;
    exgcd(b, a);
    long long c = (sum % a + a) % a, cnt = 0;
    for (int x = 0; x < la; x++) h[++h[0]] = va[i][x];
    for (int x = 0; x < lb; x++) h[++h[0]] = vb[i][x], q[++q[0]] = vb[i][x];
    sort(h + 1, h + h[0] + 1), t = 0;
    for (int x = 1; x <= h[0]; x++)
      if (h[x] != h[x - 1] || x == 1) t++, e[t].f = h[x];
    for (int x = 1; x <= t; x++)
      e[x].g = ((c * fceil(e[x].f, k)) % a - 1 + a) % a + 1;
    sort(e + 1, e + t + 1, cmp), res = 1;
    if (a == 1 && t == 1)
      continue;
    else if (t == 1)
      cnt = e[1].f + 1ll * (a - 1) * b * k;
    else {
      for (int x = 1; x <= t; x++) {
        if (x == t && !(e[1].g == 1 && (e[t].f + m - 1) % n + 1 == e[1].f))
          cnt = max(cnt, e[t].f + 1ll * e[1].g * m - m + 1ll * n * m / k -
                             1ll * e[t].g * m);
        else if (x != t && e[x].g + 1 != e[x + 1].g)
          cnt = max(cnt, e[x].f + 1ll * (e[x + 1].g - e[x].g) * m - m);
      }
    }
    ans = max(ans, cnt);
    if (cnt >= m)
      ans = max(ans, cnt);
    else
      cnt = m;
    if (q[q[0]] + k >= m && cnt == m) {
      int ct = q[q[0]];
      cnt = m;
      while (q[0] > 0 && q[q[0]] == ct) q[0]--, cnt -= k, ct -= k;
      ans = max(ans, cnt);
    }
    ans = max(ans, cnt);
  }
  cout << ans - 1 << endl;
}
