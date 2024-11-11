#include <bits/stdc++.h>
using namespace std;
inline long long add(long long a, long long b) {
  a += b;
  if (a >= 1000000007) a -= 1000000007;
  return a;
}
inline long long sub(long long a, long long b) {
  a -= b;
  if (a < 0) a += 1000000007;
  return a;
}
inline long long mul(long long a, long long b) {
  return (long long)((long long)a * b % 1000000007);
}
long long min(long long a, long long b) { return a > b ? b : a; }
long long max(long long a, long long b) { return a > b ? a : b; }
long long fact[1000005], ifact[1000005];
long long ncr(long long n, long long r) {
  if (n < r) return 0;
  return (((fact[n] * ifact[r]) % 1000000007) * ifact[n - r]) % 1000000007;
}
long long npr(long long n, long long r) {
  return (fact[n] * ifact[n - r]) % 1000000007;
}
long long binpow(long long a, long long b, long long m = 1000000007) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
void computeFact(long long maxComputeFact) {
  fact[0] = 1;
  ifact[0] = 1;
  for (int i = 1; i < maxComputeFact; i += 1) {
    fact[i] = (fact[i - 1] * i) % 1000000007;
    ifact[i] = binpow(fact[i], 1000000007 - 2, 1000000007);
  }
}
long long n, m, r;
long long x, y, b;
vector<pair<long long, long long> > vt;
vector<long long> bi;
int adj[3000];
long long com[3000][3000];
long long dp[1001][1001];
long long mdp[1001][1001];
long long func(long long y, long long x) {
  return sub(ncr(y, m), ncr(y - x, m));
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  computeFact(3000);
  cin >> n >> m >> r;
  for (int i = 0; i < n; i += 1) {
    cin >> x >> y >> b;
    vt.push_back({x, y});
    mdp[x][y] = 1;
    bi.push_back(b);
  }
  for (int i = 0; i < n; i += 1) {
    for (int j = 0; j < n; j += 1) {
      if (max(abs(vt[i].first - vt[j].first),
              abs(vt[i].second - vt[j].second)) <= r) {
        adj[i]++;
      }
    }
  }
  for (int i = 0; i < 1001; i += 1) {
    if (i)
      for (int j = 0; j < 1001; j += 1) dp[i][j] = dp[i - 1][j];
    int csum = 0;
    for (int j = 0; j < 1001; j += 1)
      if (j) {
        csum += mdp[i][j];
        dp[i][j] += csum;
      }
  }
  for (int i = 0; i < n; i += 1) {
    for (int j = 0; j < n; j += 1) {
      if (i != j && (abs(vt[i].first - vt[j].first) > 2 * r ||
                     abs(vt[i].second - vt[j].second) > 2 * r)) {
        continue;
      }
      int x1, x2, y1, y2;
      if (vt[i].first <= vt[j].first)
        x1 = max(1, vt[j].first - r), x2 = min(1000, vt[i].first + r);
      else
        x1 = max(1, vt[i].first - r), x2 = min(1000, vt[j].first + r);
      if (vt[i].second <= vt[j].second)
        y1 = max(1, vt[j].second - r), y2 = min(1000, vt[i].second + r);
      else
        y1 = max(1, vt[i].second - r), y2 = min(1000, vt[j].second + r);
      com[i][j] =
          dp[x2][y2] - dp[x2][y1 - 1] - dp[x1 - 1][y2] + dp[x1 - 1][y1 - 1];
    }
  }
  long long ans = 0;
  for (int i = 0; i < n; i += 1) {
    for (int j = 0; j < n; j += 1) {
      long long x1 = add(add(func(n - adj[j], adj[i] - com[i][j]),
                             func(n - adj[i], adj[j] - com[i][j])),
                         ncr(n - (adj[i] + adj[j] - com[i][j]), m));
      ans = add(ans, mul(mul(bi[i], bi[j]), sub(ncr(n, m), x1)));
    }
  }
  cout << ans << "\n";
}
