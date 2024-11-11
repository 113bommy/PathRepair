#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int hf = 999983;
const int N = 1e6;
long long c[N];
set<long long> cur;
map<long long, vector<pair<int, int> > > dp;
long long pw(long long a, long long b) {
  long long result = 1;
  while (b) {
    if (b & 1) result = result * a % mod;
    a = a * a % mod;
    b /= 2;
  }
  return result;
}
int p[N];
int root(int a) { return p[a] == a ? a : (p[a] = root(p[a])); }
void merge(int a, int b) {
  a = root(a), b = root(b);
  if (a != b) p[a] = b;
}
int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; i++) scanf("%lld", &c[i]), p[i] = i;
  for (int i = 1; i <= m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    dp[c[a] ^ c[b]].push_back(pair<int, int>(a, b));
    cur.insert(c[a] ^ c[b]);
  }
  long long ans = ((1ll << k) - cur.size()) % mod * pw(2, n) % mod;
  for (auto its : cur) {
    long long val = its;
    int m = n;
    for (int j = 0; j < dp[val].size(); j++) {
      int a = dp[val][j].first, b = dp[val][j].second;
      if (root(a) != root(b)) merge(a, b), m--;
    }
    ans = (ans + pw(2, m)) % mod;
    for (int j = 0; j < dp[val].size(); j++) {
      int a = dp[val][j].first, b = dp[val][j].second;
      p[a] = a;
      p[b] = b;
    }
  }
  printf("%lld\n", ans);
}
