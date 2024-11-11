#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
long long count_set_bits(long long n) {
  bitset<63> a(n);
  return a.count();
}
long long mod = 1e9 + 7;
long long power(long long x, long long n) {
  if (n == 0) return 1;
  if (n == 1) return x % mod;
  if (n % 2 == 0) {
    long long y = power(x, n / 2) % mod;
    return (y * y) % mod;
  }
  if (n & 1) {
    long long y = power(x, n - 1);
    return (x % mod * y % mod) % mod;
  }
}
const long long MAXN = 500005;
void solve() {
  long long n, i, j, k, h, w;
  cin >> h >> w;
  string s[h];
  for (i = 0; i < h; i++) cin >> s[i];
  if (h < 3 || w < 3)
    cout << "NO";
  else {
    long long r = -1, c = -1;
    for (i = 1; i < h - 1; i++) {
      for (j = 1; j < w - 1; j++) {
        if (s[i][j] == '*' && s[i - 1][j] == '*' && s[i + 1][j] == '*' &&
            s[i][j - 1] == '*' && s[i][j + 1] == '*') {
          r = i, c = j;
          break;
        }
      }
    }
    if (r == -1 && c == -1) {
      cout << "NO";
      exit(0);
    } else {
      for (i = r; i < h; i++) {
        if (s[i][c] == '*')
          s[i][c] = '#';
        else
          break;
      }
      for (i = r - 1; i >= 0; i--) {
        if (s[i][c] == '*')
          s[i][c] = '#';
        else
          break;
      }
      for (i = c + 1; i < w; i++) {
        if (s[r][i] == '*')
          s[r][i] = '#';
        else
          break;
      }
      for (i = c - 1; i >= 0; i--) {
        if (s[r][i] == '*')
          s[r][i] = '#';
        else
          break;
      }
      for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) {
          if (s[i][j] == '*') {
            cout << "NO";
            exit(0);
          }
        }
      }
      cout << "YES";
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long t = 1;
  while (t--) solve();
  return 0;
}
