#include <bits/stdc++.h>
using namespace std;
const int MAX_P = 40000010, N = 10010, MAX_N = 100010;
const long long inf = 1e17;
int p[MAX_P], t, ans[N];
map<long long, vector<pair<long long, int> > > M;
inline void Pre(const int &n) {
  for (int i = 2; i <= n; i++) {
    if (!p[i]) p[++*p] = i;
    for (int j = 1; j <= *p && 1LL * i * p[j] <= n; j++)
      if (p[p[j] * i] = 1, i % p[j] == 0) break;
  }
}
int m, res;
long long fac[N];
void exgcd(long long x, long long y, long long &a, long long &b) {
  if (!y) {
    a = 1;
    b = 0;
    return;
  }
  exgcd(y, x % y, b, a);
  b -= (x / y) * a;
}
long long dis[MAX_N];
priority_queue<pair<long long, int> > Q;
long long a, b;
inline void solve(long long k) {
  m = 0;
  for (int i = 1; i <= *p && 1LL * p[i] * p[i] <= k; i++)
    if (k % p[i] == 0) {
      fac[++m] = p[i];
      while (k % p[i] == 0) k /= p[i];
    }
  if (k ^ 1) fac[++m] = k;
  if (m <= 1) return;
  if (m == 2) {
    exgcd(fac[1], fac[2], a, b);
    b = (b % fac[1] + fac[1]) % fac[1];
    return;
  }
  for (int i = 0; i < fac[1]; i++) dis[i] = inf;
  dis[0] = 0;
  Q.push(pair<long long, int>(0, 0));
  while (!Q.empty()) {
    int x = Q.top().second;
    long long d = -Q.top().first;
    Q.pop();
    if (d != dis[x]) continue;
    for (int i = 1; i <= m; i++)
      if (dis[(x + fac[i]) % fac[1]] > dis[x] + fac[i]) {
        dis[(x + fac[i]) % fac[1]] = dis[x] + fac[i];
        Q.push(pair<long long, int>(-dis[(x + fac[i]) % fac[1]],
                                    (x + fac[i]) % fac[1]));
      }
  }
}
int main() {
  scanf("%d", &t);
  Pre(MAX_P - 10);
  for (int i = 1; i <= t; i++) {
    long long n, k;
    scanf("%lld%lld", &n, &k);
    M[k].push_back(pair<long long, int>(n, i));
  }
  for (auto Z : M) {
    vector<pair<long long, int> > &cur = Z.second;
    long long k = Z.first;
    solve(k);
    for (auto x : cur) {
      if (!m)
        ans[x.second] = 0;
      else if (m == 1)
        ans[x.second] = !(x.first % fac[1]);
      else if (m == 2) {
        long long c = b * (x.first % fac[1]) % fac[1] * fac[2];
        ans[x.second] = c <= x.first;
        a = -a;
      } else
        ans[x.second] = x.first >= dis[x.first % fac[1]];
    }
  }
  for (int i = 1; i <= t; i++) puts(ans[i] ? "YES" : "NO");
  return 0;
}
