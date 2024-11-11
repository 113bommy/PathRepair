#include <bits/stdc++.h>
using namespace std;
int h, w, n;
vector<pair<int, int> > v;
long long dp[2007];
long long fac[300007];
long long inv[300007];
long long FASTPOW(long long a, long long x) {
  long long r = 1;
  while (x != 0) {
    if (x % 2 == 0) {
      a = a * a;
      a %= 1000000007;
      x /= 2;
    } else {
      r = r * a;
      r %= 1000000007;
      x--;
    }
  }
  return r;
}
void input();
void solve();
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  input();
  solve();
  return 0;
}
void input() {
  scanf("%d%d%d", &h, &w, &n);
  v.resize(n);
  int i;
  for (i = 0; i < n; i++) {
    scanf("%d%d", &v[i].first, &v[i].second);
  }
  v.push_back(make_pair(h, w));
  sort(v.begin(), v.end());
}
void solve() {
  int i, j;
  long long cur = 1;
  fac[0] = inv[0] = 1;
  for (i = 1; i < 300007; i++) {
    cur *= i;
    cur %= 1000000007;
    fac[i] = cur;
    inv[i] = FASTPOW(cur, 1000000007 - 2);
  }
  dp[0] = fac[v[0].first + v[0].second - 2] * inv[v[0].first - 1];
  dp[0] %= 1000000007;
  dp[0] *= inv[v[0].second - 1];
  dp[0] %= 1000000007;
  for (i = 1; i <= n; i++) {
    cur = fac[v[i].first + v[i].second - 2];
    cur *= inv[v[i].first - 1];
    cur %= 1000000007;
    cur *= inv[v[i].second - 1];
    cur %= 1000000007;
    for (j = i - 1; j >= 0; j--) {
      if (v[j].first > v[i].first || v[j].second > v[i].second) {
        continue;
      }
      long long g;
      g = fac[v[i].first + v[i].second - v[j].first - v[j].second];
      g *= inv[v[i].first - v[j].first];
      g %= 1000000007;
      g *= inv[v[i].second - v[j].second];
      g %= 1000000007;
      g *= dp[j];
      g %= 1000000007;
      cur = (cur + 1000000007 - g) % 1000000007;
    }
    dp[i] = cur;
  }
  printf("%I64d\n", dp[n]);
}
