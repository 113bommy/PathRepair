#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
const long long N = 2e5 + 10;
const long long mod = 1e9 + 7;
long long b[30][N];
long long h[30][N];
long long calc[N];
long long get(long long i, long long j, long long len) {
  long long i1 = i + len - 1;
  long long j1 = j + len - 1;
  long long h1 = 0, h2 = 0;
  set<long long> s1, s2;
  for (long long l = 0; l < 26; l++) {
    long long hh1 = h[l][i1];
    if (i > 0) hh1 -= h[l][i - 1];
    long long hh2 = h[l][j1];
    if (j > 0) hh2 -= h[l][j - 1];
    hh1 += mod;
    hh1 %= mod;
    hh2 += mod;
    hh2 %= mod;
    if (i > j)
      hh2 *= calc[i - j];
    else
      hh1 *= calc[j - i];
    hh1 %= mod;
    hh2 %= mod;
    s1.insert(hh1 % mod);
    s2.insert(hh2 % mod);
  }
  return (s1 == s2);
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  long long q;
  cin >> q;
  string s;
  cin >> s;
  for (long long i = 0; i < n; i++) b[s[i] - 'a'][i] = 2;
  calc[0] = 1;
  for (long long i = 0; i < 26; i++) {
    if (b[i][0] == 0) b[i][0] = 10006;
    h[i][0] = b[i][0] + 1;
    long long p = 31;
    for (long long j = 1; j < n; j++) {
      if (b[i][j] == 0) b[i][j] = 10006;
      calc[j] = p;
      calc[j] %= mod;
      h[i][j] = h[i][j - 1] + (b[i][j] + 1) * p;
      h[i][j] %= mod;
      p *= 31;
      p %= mod;
    }
  }
  while (q--) {
    long long x, y, len;
    cin >> x >> y >> len;
    x--;
    y--;
    if (get(x, y, len))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
