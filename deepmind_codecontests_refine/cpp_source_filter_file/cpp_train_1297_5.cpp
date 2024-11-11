#include <bits/stdc++.h>
using namespace std;
int n, m;
double res;
double ans[99];
string s[99];
long long a[1 << 20], b[1 << 20];
int len[1 << 20];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  m = (int((s[0]).size()));
  for (int i = 1; i <= m; i++) {
    ans[i] = i;
    for (int j = 0; j < i; j++) {
      if (j + 1 < i) {
        ans[i] *= (j + 1.0) / (m - j);
      } else {
        ans[i] /= m - j;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) {
        continue;
      }
      int cur = 0;
      for (int k = 0; k < m; k++) {
        if (s[i][k] == s[j][k]) {
          cur |= 1 << k;
        }
      }
      a[cur] |= 1LL << i;
    }
  }
  for (int i = (1 << m) - 1; i > 0; i--) {
    if (!a[i]) {
      continue;
    }
    for (int k = 1; k <= i; k <<= 1) {
      k = ((i - k) & i) ^ i;
      a[i ^ k] |= a[i];
    }
  }
  for (int i = 0; i < (1 << m); i++) {
    if (!a[i]) {
      continue;
    }
    int x = ((1 << m) - 1) ^ i;
    double add = ans[__builtin_popcount(i) + 1];
    for (int k = 1; k <= x; k <<= 1) {
      k = ((x - k) & x) ^ x;
      res += add * __builtin_popcount((((1LL << n) - 1) ^ a[i ^ k]) & a[i]);
    }
  }
  printf("%.12lf\n", res / n);
  return 0;
}
