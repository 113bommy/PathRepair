#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18 + 1e17;
const long long mod = 998244353;
long long modInverse(long long a, long long m) {
  long long m0 = m;
  long long y = 0, x = 1;
  if (m == 1) return 0;
  while (a > 1) {
    long long q = a / m;
    long long t = m;
    m = a % m, a = t;
    t = y;
    y = x - q * y;
    x = t;
  }
  if (x < 0) x += m0;
  return x;
}
long long powm(long long a, long long b) {
  a = a % mod;
  long long res = 1;
  while (b) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return (res % mod);
}
const long long N = 3e5 + 5;
void solve() {
  int n, m;
  cin >> n >> m;
  string s[n];
  for (int i = 0; i < n; i++) cin >> s[i];
  string ans = s[n - 1];
  string tt = "";
  for (int i = 0; i < 26; i++) tt += (char)(i + 'a');
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < m; j++) {
      string tp = ans;
      tp[j] = tt[i];
      bool bo = true;
      for (int k = 0; k < n; k++) {
        int cnt = 0;
        for (int l = 0; l < m; l++) {
          if (tp[l] != s[k][l]) cnt++;
        }
        if (cnt > 2) bo = false;
      }
      if (bo) {
        cout << tp << '\n';
        return;
      }
    }
  }
  cout << -1 << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  for (long long i = 1; i <= t; i++) {
    solve();
  }
}
