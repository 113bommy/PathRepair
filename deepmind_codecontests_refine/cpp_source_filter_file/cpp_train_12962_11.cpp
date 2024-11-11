#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
long long const inf = 1e18, linf = 2e9, mod = 1e9 + 7, inf2 = 1e12;
int const mxn = 2e6 + 10;
long long poww(long long a, long long b, long long md) {
  return (!b ? 1
             : (b & 1 ? a * poww(a * a % md, b / 2, md) % md
                      : poww(a * a % md, b / 2, md) % md));
}
long long mods[2] = {1000000007, 1000000009};
long long hash1[2][mxn], hash2[2][mxn], id[300], s1[mxn], s2[mxn];
int main() {
  int n;
  cin >> n;
  n = n - 1;
  id['N'] = 0;
  id['S'] = 3;
  id['E'] = 2;
  id['W'] = 1;
  for (int i = n; i >= 1; i--) {
    char a;
    cin >> a;
    s1[i] = id[a];
  }
  for (int i = n; i >= 1; i--) {
    char a;
    cin >> a;
    s2[i] = 3 - id[a];
  }
  int t = 1;
  for (int i = 2; i <= n; i++) {
    hash1[0][i] = (hash1[0][i - 1] * 4 + s1[i]) % mods[0];
    hash2[0][i] = (hash2[0][i - 1] + s2[i] * poww(4, i - 1, mods[0])) % mods[0];
    hash1[1][i] = (hash1[1][i - 1] * 4 + s1[i]) % mods[1];
    hash2[1][i] = (hash2[1][i - 1] + s2[i] * poww(4, i - 1, mods[1])) % mods[1];
    if (hash2[0][i] == hash1[0][i] and hash1[1][i] == hash2[1][i]) t = 0;
  }
  if (t)
    cout << "YES";
  else
    cout << "NO";
}
