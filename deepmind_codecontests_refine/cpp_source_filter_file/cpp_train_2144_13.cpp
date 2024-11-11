#include <bits/stdc++.h>
using namespace std;
long long inline gcd(long long x, long long y) {
  return !y ? (long long)abs(x) : gcd(y, x % y);
}
long long inline lcm(long long a, long long b) {
  return ((long long)abs((a / gcd(a, b)) * b));
}
double inline cartesian_dist(double x1, double y1, double x2, double y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
long long bigmod(long long b, long long p, long long m) {
  if (!p)
    return 1 % m;
  else if (p & 1)
    return (((b % m) + m) % m * bigmod(b, p - 1, m)) % m;
  else {
    long long ret = bigmod(b, p / 2, m);
    return (ret * ret) % m;
  }
}
long long inverse(long long a, long long m) { return bigmod(a, m - 2, m); }
long long extended(long long a, long long m) {
  long long oldr = a, r = m, oldans = 1, ans = 0, quotient;
  while (r) {
    quotient = oldr / r;
    oldr = oldr - r * quotient;
    swap(oldr, r);
    oldans = oldans - ans * quotient;
    swap(oldans, ans);
  }
  return ((oldans % m) + m) % m;
}
const double PI = acos(-1.0);
const double EPS = 10E-7;
const int MAX = (int)1e7;
vector<pair<int, int> > vec[85];
int dp[82][82][82][82];
int rec(int now, int l, int r, int used) {
  if (used == 1) return 0;
  if (dp[now][l][r][used] != -1) return dp[now][l][r][used];
  int ret = MAX;
  for (int i = 0; i < vec[now].size(); i++) {
    int v = vec[now][i].first;
    int w = vec[now][i].second;
    if (l < v && v < r) {
      ret = min(ret, w + rec(v, l, v, used - 1));
      ret = min(ret, w + rec(v, v, r, used - 1));
    }
  }
  return dp[now][l][r][used] = ret;
}
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  int m;
  scanf("%d", &m);
  while (m--) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    vec[u].push_back(make_pair(v, w));
  }
  memset(dp, -1, sizeof(dp));
  int ans = INT_MAX;
  for (int i = 1; i <= n; i++) {
    ans = min(ans, rec(i, 0, i, k));
    ans = min(ans, rec(i, i, n + 1, k));
  }
  ans == INT_MAX ? cout << "-1\n" : cout << ans << endl;
  return 0;
}
