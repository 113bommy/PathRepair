#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const long long inf = 1e18;
int n, m, cnt, id[N], rk[N];
long long dis[N];
vector<int> boy[N], gir[N];
long long ans;
bool cmp(int x, int y) {
  if (rk[x] == rk[y]) {
    return x < y;
  }
  return rk[x] < rk[y];
}
long long exgcd(long long a, long long b, long long &x, long long &y) {
  if (b == 0) {
    x = 1, y = 0;
    return a;
  }
  long long g = exgcd(b, a % b, x, y);
  long long t = x;
  x = y;
  y = t - (a / b) * y;
  return g;
}
long long solve(int n, int m, int x, vector<int> a, vector<int> b) {
  if (a.size() == n) {
    return -1;
  }
  cnt = 0;
  for (unsigned i = 0; i < a.size(); i++) {
    rk[++cnt] = (1ll * x * a[i]) % n;
    dis[cnt] = a[i], id[cnt] = cnt;
  }
  for (unsigned i = 0; i < b.size(); i++) {
    rk[++cnt] = (1ll * x * b[i]) % n;
    dis[cnt] = b[i], id[cnt] = cnt;
  }
  sort(id + 1, id + cnt + 1, cmp);
  id[0] = 0, rk[0] = rk[id[cnt]] - n;
  id[cnt + 1] = cnt + 1, rk[cnt + 1] = rk[id[1]] + n;
  long long res = 0, sum = inf;
  for (int i = 1; i <= cnt; i++) {
    sum = min(sum + 1ll * (rk[id[i]] - rk[id[i - 1]]) * m, dis[id[i]]);
  }
  for (int i = 1; i <= cnt; i++) {
    sum = min(sum + 1ll * (rk[id[i]] - rk[id[i - 1]]) * m, dis[id[i]]);
    if (rk[id[i]] == rk[id[i + 1]]) {
      continue;
    }
    if (rk[id[i]] + 1 == rk[id[i + 1]] && id[i] <= a.size()) {
      continue;
    }
    res = max(res, sum + 1ll * (rk[id[i + 1]] - rk[id[i]] - 1) * m);
  }
  return res;
}
int main() {
  scanf("%d%d", &n, &m);
  long long X, Y;
  int d = exgcd(m, n, X, Y), b, g;
  X = ((X % n) + n) % n, Y = ((Y % m) + m) % m;
  n /= d, m /= d;
  if (d > 2e5) {
    printf("-1\n");
    return 0;
  }
  scanf("%d", &b);
  for (int i = 1, x; i <= b; i++) {
    scanf("%d", &x);
    boy[x % d].push_back(x / d);
  }
  scanf("%d", &g);
  for (int i = 1, x; i <= g; i++) {
    scanf("%d", &x);
    gir[x % d].push_back(x / d);
  }
  for (int i = 0; i < d; i++) {
    if (boy[i].empty() && gir[i].empty()) {
      printf("-1\n");
      return 0;
    }
    ans = max(ans, solve(n, m, X, boy[i], gir[i]) * d + i);
    ans = max(ans, solve(m, n, Y, gir[i], boy[i]) * d + i);
  }
  printf("%lld\n", ans);
  return 0;
}
