#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-ffloat-store")
#pragma GCC optimize("-fno-defer-pop")
long long int power(long long int a, long long int b, long long int m) {
  if (b == 0) return 1;
  if (b == 1) return a % m;
  long long int t = power(a, b / 2, m) % m;
  t = (t * t) % m;
  if (b & 1) t = ((t % m) * (a % m)) % m;
  return t;
}
long long int modInverse(long long int a, long long int m) {
  return power(a, m - 2, m);
}
int f1[2000010], f2[2000010], fl[2000010], trie[2000010][30];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string a, b, c;
  cin >> a >> b >> c;
  long long int i, j, k, l, n, x, y;
  n = a.length();
  x = b.length();
  y = c.length();
  for (i = 0; i < n; i++) {
    j = 0;
    while (j < x && b[j] == a[i + j]) {
      j++;
    }
    if (j == x) f1[i] = 1;
  }
  for (i = n - 1; i >= 0; i--) {
    j = y - 1;
    k = 0;
    while (j >= 0 && c[j] == a[i - k]) {
      k++;
      j--;
    }
    if (k == y) {
      f2[i] = 1;
    }
  }
  long long int level, nodes = 0;
  for (i = 0; i < n; i++) {
    if (f1[i]) {
      level = 0;
      for (j = i; j < n; j++) {
        if (trie[level][a[j] - 'a'] == 0) {
          nodes++;
          trie[level][a[j] - 'a'] = nodes;
        }
        level = trie[level][a[j] - 'a'];
        if (f2[j] && (j - i + 1 >= x && j - i + 1 >= y)) {
          fl[level] = 1;
        }
      }
    }
  }
  long long int ans = 0;
  for (i = 1; i <= nodes; i++) {
    if (fl[i]) ans++;
  }
  cout << ans;
  return 0;
}
