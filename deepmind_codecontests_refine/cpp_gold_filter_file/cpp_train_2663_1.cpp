#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("avx2")
#pragma GCC optimization("unroll-loops")
#pragma GCC optimize("O2")
constexpr int dx[] = {-1, 0, 1, 0, 1, 1, -1, -1};
constexpr int dy[] = {0, -1, 0, 1, 1, -1, 1, -1};
constexpr long long INF = 1999999999999999997;
constexpr int inf = INT_MAX;
constexpr int MAXSIZE = int(1e6) + 5;
constexpr auto PI = 3.14159265358979323846L;
constexpr auto oo = numeric_limits<int>::max() / 2 - 2;
constexpr auto eps = 1e-6;
constexpr auto mod = 1000000007;
constexpr auto MOD = 1000000007;
constexpr auto MOD9 = 1000000009;
constexpr auto maxn = 100006;
void fastio() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
long long dp[1002][1002];
long long a[26];
int maxi = 1;
int cnt = 0;
int n;
string s;
long long solve(int ind, int len, long long mini) {
  if (ind == n) return 1;
  long long &res = dp[ind][len];
  if (res != -1) return res;
  res = 0;
  if (min(mini, a[s[ind] - 'a']) > len) {
    res += solve(ind + 1, len + 1, min(mini, a[s[ind] - 'a']));
    maxi = max(maxi, len + 1);
    res %= mod;
    res += solve(ind + 1, 1, a[s[ind] - 'a']);
    res %= mod;
  } else {
    res += solve(ind + 1, 1, a[s[ind] - 'a']);
    maxi = max(maxi, 1);
    res %= mod;
  }
  return res;
}
int main() {
  fastio();
  cin >> n;
  cin >> s;
  for (int i = 0; i < 26; i++) {
    cin >> a[i];
  }
  for (int i = 0; i <= 1000; i++)
    for (int j = 0; j <= 1000; j++) dp[i][j] = -1;
  long long ans = 0;
  ans += solve(1, 1, a[s[0] - 'a']);
  ans %= mod;
  int l = a[s[0] - 'a'];
  int p = 1;
  for (int i = 1; i < s.length(); i++) {
    l = min(l, (int)a[s[i] - 'a']);
    p++;
    if (l < p) {
      p = 1;
      cnt++;
      l = a[s[i] - 'a'];
    }
  }
  cout << ans << "\n";
  cout << maxi << "\n";
  cout << cnt + 1 << "\n";
}
