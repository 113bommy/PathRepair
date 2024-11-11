#include <bits/stdc++.h>
using namespace std;
int n, m, phi;
inline int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
inline int pow(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) res = 1ll * res * a % m;
    a = 1ll * a * a % m;
    b >>= 1;
  }
  return res;
}
inline int solve(int a, int b) {
  int g = gcd(a, b);
  a /= g, b /= g;
  return 1ll * pow(a, phi - 1) * b % m;
}
bool forbidden[200005];
vector<int> G[200005];
int dp[200005], pre[200005];
int seq[200005], ans = 0;
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  phi = m;
  int mm = m;
  for (int tmp = 2; tmp <= m; ++tmp) {
    if (mm % tmp == 0) {
      phi = 1ll * phi * (tmp - 1) / tmp;
    }
    while (mm % tmp == 0) mm /= tmp;
  }
  memset(forbidden, 0, sizeof(forbidden));
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    if (x == 0) x = m;
    forbidden[x] = 1;
  }
  for (int i = 1; i <= m; ++i) {
    if (forbidden[i]) continue;
    G[gcd(i, m)].push_back(i);
  }
  for (int i = 1; i <= m; ++i) {
    if (m % i) continue;
    dp[i] += G[i].size();
    for (int j = i + i; j <= m; j += i) {
      if (m % j) continue;
      if (dp[j] < dp[i]) {
        dp[j] = dp[i];
        pre[j] = i;
      }
    }
  }
  int cur = m;
  while (1) {
    for (int i = 0; i < G[cur].size(); ++i) seq[++ans] = G[cur][i];
    if (cur == 1) break;
    cur = pre[cur];
  }
  cout << ans << endl;
  cout << seq[ans] % m << " ";
  for (int i = ans - 1; i > 0; --i) cout << solve(seq[i + 1], seq[i]) << " ";
  return 0;
}
