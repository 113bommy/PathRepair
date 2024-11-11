#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
int n, m, a, b, g;
int dis[N];
long long ans, c[N];
long long sum(int u) { return 1LL * u * (u + 1) / 2; }
long long query(int u) {
  return sum(u / g + 1) * g - 1LL * (u / g + 1) * ((g - ((u + 1) % g)) % g);
}
int gcd(int u, int v) {
  if (v == 0) {
    return u;
  }
  return gcd(v, u % v);
}
set<pair<int, int> > s;
int main() {
  scanf("%d%d%d", &n, &a, &b);
  g = gcd(a, b);
  if (n > a + b - g) {
    ans += query(n) - query(a + b - g);
    n = a + b - g;
  }
  memset(dis, 0x3f, sizeof dis);
  dis[0] = 0;
  s.insert({0, 0});
  while (!s.empty()) {
    auto u = *s.begin();
    s.erase(s.begin());
    if (dis[u.second] != u.first) {
      continue;
    }
    ++c[u.first];
    if (u.second >= b && u.first < dis[u.second - b]) {
      dis[u.second - b] = u.first;
      s.insert({u.first, u.second - b});
    }
    if (u.second + a <= n && max(u.first, u.second + a) < dis[u.second + a]) {
      dis[u.second + a] = max(u.first, u.second + a);
      s.insert({max(u.first, u.second + a), u.second + a});
    }
  }
  for (int i = 1; i <= n; i++) {
    c[i] += c[i - 1];
  }
  for (int i = 0; i <= n; i++) {
    ans += c[i];
  }
  printf("%lld\n", ans);
  return 0;
}
