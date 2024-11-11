#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
long long POW(long long a, long long b, long long MMM = MOD) {
  long long ret = 1;
  for (; b; b >>= 1, a = (a * a) % MMM)
    if (b & 1) ret = (ret * a) % MMM;
  return ret;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long lcm(long long a, long long b) {
  if (a == 0 || b == 0) return a + b;
  return a * (b / gcd(a, b));
}
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
int ddx[] = {0, 0, 1, 1, 1, -1, -1, -1}, ddy[] = {1, -1, 1, 0, -1, 1, 0, -1};
vector<int> v[200001];
pair<int, int> dfs(int N, int p) {
  vector<pair<int, int> > vv;
  for (int next : v[N]) {
    if (next == p) continue;
    vv.push_back(dfs(next, N));
  }
  if (vv.empty()) return make_pair(1, 987654321);
  sort(vv.begin(), vv.end(), [&](pair<int, int> p1, pair<int, int> p2) {
    return p1.first - min(p1.first, p2.second) <
           p2.first - min(p2.first, p2.second);
  });
  pair<int, int> r = make_pair(0, 0);
  int n = vv.size();
  r.first += vv[0].first;
  for (int(i) = (1); (i) <= (n - 1); (i) += (1))
    r.first += min(vv[i].first, vv[i].second);
  if (n == 1)
    r.second = 987654321;
  else {
    r.second += vv[0].first + vv[1].first - 1;
    for (int(i) = (2); (i) <= (n - 1); (i) += (1))
      r.second += min(vv[i].first, vv[i].second);
  }
  return r;
}
int main() {
  int n;
  long long x, y;
  scanf("%d%lld%lld", &n, &x, &y);
  for (int(i) = (1); (i) <= (n - 1); (i) += (1)) {
    int xx, yy;
    scanf("%d%d", &xx, &yy);
    v[xx].push_back(yy);
    v[yy].push_back(xx);
  }
  if (x >= y) {
    for (int(i) = (1); (i) <= (n); (i) += (1))
      if (v[i].size() == n - 1) return !printf("%lld", x + y * (n - 2));
    return !printf("%lld", y * (n - 1));
  }
  pair<int, int> p = dfs(1, -1);
  int t = min(p.first, p.second);
  printf("%lld", x * (n - t) + y * (t - 1));
}
