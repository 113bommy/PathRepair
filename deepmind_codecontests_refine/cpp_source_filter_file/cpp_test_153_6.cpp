#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<array<int, 26>> a(n);
  for (int i = 0; i < n; i++) {
    string str;
    cin >> str;
    for (int j = 0; j < 26; j++) {
      a[i][j] = 0;
    }
    for (int j = 0; j < str.size(); j++) {
      int ch = (int)(str[j] - 'a');
      a[i][ch]++;
    }
  }
  long long mod = 998244353;
  vector<long long> f(1 << n);
  for (int i = 1; i < (1 << n); i++) {
    array<int, 26> ar{};
    for (int j = 0; j < 26; j++) {
      ar[j] = mod;
    }
    for (int j = 0; j < n; j++) {
      if ((i >> j) & 1) {
        for (int k = 0; k < 26; k++) {
          ar[k] = min(ar[k], a[j][k]);
        }
      }
    }
    long long v = 1;
    for (int j = 0; j < 26; j++) {
      v = v * (ar[j] + 1) % mod;
    }
    if (__builtin_popcount(i) & 1) {
      f[i] = v;
    } else {
      f[i] = -v;
    }
  }
  vector<long long> g = f;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < (1 << n); j++) {
      if ((j >> i) & 1) {
        g[j] = (g[j] + g[j ^ (1 << i)]) % mod;
      }
    }
  }
  long long res = 0;
  for (int i = 0; i < (1 << n); i++) {
    long long coef = 0;
    for (int j = 0; j < n; j++) {
      if ((i >> j) & 1) {
        coef += j + 1;
      }
    }
    coef *= __builtin_popcount(i);
    res ^= (coef * g[i]);
  }
  cout << res << "\n";
  return 0;
}
