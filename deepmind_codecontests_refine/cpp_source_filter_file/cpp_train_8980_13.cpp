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
vector<pair<long long, long long>> vt;
vector<long long> bi;
set<long long> adj[3000];
long long com[3000][3000];
long long func(long long y, long long x) {
  return sub(ncr(y, m), ncr(y - x, m));
}
long long diff(set<long long> &a, set<long long> &b) {
  set<long long> tmp;
  for (auto it : a) {
    tmp.insert(it);
  }
  for (auto it : b) {
    tmp.insert(it);
  }
  return (int)((a).size()) + (int)((b).size()) - (int)((tmp).size());
}
long long dp[1001][1001];
void calc(vector<pair<long long, long long>> &v, long long r) {
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < v.size(); i++) {
    dp[v[i].first][v[i].second] = 1;
  }
  for (int i = 1; i <= 1000; i++) {
    for (int j = 1; j <= 1000; j++)
      dp[i][j] += dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      long long xx1 = v[i].first, xx2 = v[j].first, yy1 = v[i].second,
                yy2 = v[j].second;
      if (min(xx1, xx2) + r <= max(xx1, xx2) - r ||
          min(yy1, yy2) + r <= max(yy1, yy2) - r) {
        com[i][j] = 0;
        continue;
      } else {
        long long xz[4] = {xx1 + r, xx2 + r, xx1 - r, xx2 - r};
        long long yz[4] = {yy1 + r, yy2 + r, yy1 - r, yy2 - r};
        sort(xz, xz + 4);
        sort(yz, yz + 4);
        long long x1 = max(1, xz[1]), x2 = min(1000, xz[2]);
        long long y1 = max(1, yz[1]), y2 = min(1000, yz[2]);
        com[i][j] =
            dp[x2][y2] + dp[x1 - 1][y1 - 1] - dp[x1 - 1][y2] - dp[x2][y1 - 1];
      }
    }
  }
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
    bi.push_back(b);
  }
  for (int i = 0; i < n; i += 1) {
    for (int j = 0; j < n; j += 1) {
      if (max(abs(vt[i].first - vt[j].first),
              abs(vt[i].second - vt[j].second)) <= r) {
        adj[i].insert(j);
        adj[j].insert(i);
      }
    }
  }
  calc(vt, r);
  long long ans = 0;
  for (int i = 0; i < n; i += 1) {
    for (int j = 0; j < n; j += 1) {
      long long x1 = add(
          add(func(n - (int)((adj[j]).size()),
                   (int)((adj[i]).size()) - com[i][j]),
              func(n - (int)((adj[i]).size()),
                   (int)((adj[j]).size()) - com[i][j])),
          ncr(n - ((int)((adj[i]).size()) + (int)((adj[j]).size()) - com[i][j]),
              m));
      ans = add(ans, mul(mul(bi[i], bi[j]), sub(ncr(n, m), x1)));
    }
  }
  cout << ans << "\n";
}
