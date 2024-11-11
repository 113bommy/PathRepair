#include <bits/stdc++.h>
using namespace std;
long long fac[200005];
long long inv[200005];
inline void add(long long &a, long long b) {
  a %= 1000000007;
  b %= 1000000007;
  a += b;
  a %= 1000000007;
}
inline void sub(long long &a, long long b) {
  a %= 1000000007;
  b %= 1000000007;
  a -= b;
  if (a < 0) a += 1000000007;
}
inline void mul(long long &a, long long b) {
  a %= 1000000007;
  b %= 1000000007;
  a *= b;
  a %= 1000000007;
}
long long powm(long long a, long long b) {
  long long ret = 1ll;
  while (b) {
    if (b & 1) ret = (1ll * ret * a) % 1000000007;
    a = (1ll * a * a) % 1000000007;
    b /= 2;
  }
  return ret;
}
long long modInv(long long a) { return powm(a, 1000000007 - 2); }
void pre() {
  fac[0] = 1ll;
  for (int i = 1; i < 200005; i++) fac[i] = (1ll * fac[i - 1] * i) % 1000000007;
  for (int i = 0; i < 200005; i++) inv[i] = modInv(fac[i]);
}
long long ncr(long long a, long long b) {
  long long ret = (((inv[b] * inv[a - b]) % 1000000007) * fac[a]) % 1000000007;
  return ret;
}
vector<pair<int, int> > black;
long long dp[200005];
int main() {
  int rows, cols, n, l, r;
  cin >> rows >> cols >> n;
  for (int i = 0; i < n; i++) {
    cin >> l >> r;
    l--;
    r--;
    black.push_back(make_pair(l, r));
  }
  black.push_back(make_pair(rows - 1, cols - 1));
  sort(black.begin(), black.end());
  n++;
  pre();
  for (int i = 0; i < n; i++) {
    dp[i] =
        ncr(1ll * (black[i].first + black[i].second), 1ll * black[i].second);
    for (int j = 0; j < i; j++) {
      if (black[j].second <= black[i].second) {
        int dl = black[i].first - black[j].first;
        int dr = black[i].second - black[j].second;
        sub(dp[i], 1ll * dp[j] * ncr(1ll * dl + 1ll * dr, 1ll * dr));
      }
    }
  }
  cout << dp[n - 1];
  return 0;
}
