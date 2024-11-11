#include <bits/stdc++.h>
#pragma warning(disable : 4996)
#pragma comment(linker, "/STACK:16777216")
using namespace std;
const int INF = 1000000000 + 1e8;
const long long LINF = 2000000000000000000;
const int N = 4e6 + 1010;
long long dp[N];
long long pref[N];
long long n, mod;
long long get(int l, int r) {
  return (pref[l] - (r >= n ? 0 : pref[r + 1]) + 2 * mod) % mod;
}
void solve() {
  cin >> n >> mod;
  dp[n] = 1, pref[n] = 1;
  int l, r;
  for (int i = n - 1; i >= 1; i--) {
    dp[i] = pref[i + 1] % mod;
    for (int x = 2; i * x <= n; x++) {
      l = i * x;
      r = i * x + x - 1;
      dp[i] = (dp[i] + get(l, r)) % mod;
    }
    pref[i] = (pref[i + 1] + dp[i]) % mod;
  }
  cout << dp[1];
}
int main() {
  srand(time(0));
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tst = 1;
  while (tst--) solve();
}
