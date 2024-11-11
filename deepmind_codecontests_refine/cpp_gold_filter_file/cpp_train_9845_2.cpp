#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7, N = 2e6 + 7, M = 2e6 + 7, INF = INT_MAX / 10;
long long powe(long long x, long long y) {
  x = x % mod, y = y % (mod - 1);
  long long ans = 1;
  while (y > 0) {
    if (y & 1) {
      ans = (1ll * x * ans) % mod;
    }
    y >>= 1;
    x = (1ll * x * x) % mod;
  }
  return ans;
}
void solve() {
  int games, counta = 0, countd = 0;
  string s;
  cin >> games >> s;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == 'A')
      counta++;
    else
      countd++;
  }
  (counta > countd)
      ? cout << "Anton"
      : ((countd == counta) ? cout << "Friendship" : cout << "Danik");
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
