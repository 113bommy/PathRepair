#include <bits/stdc++.h>
using namespace std;
int getint() {
  unsigned int c;
  int x = 0;
  while (((c = getchar()) - '0') >= 10) {
    if (c == '-') return -getint();
    if (!~c) exit(0);
  }
  do {
    x = (x << 3) + (x << 1) + (c - '0');
  } while (((c = getchar()) - '0') < 10);
  return x;
}
int getstr(char *s) {
  int c, n = 0;
  while ((c = getchar()) <= ' ') {
    if (!~c) exit(0);
  }
  do {
    s[n++] = c;
  } while ((c = getchar()) > ' ');
  s[n] = 0;
  return n;
}
template <class T>
inline bool chmin(T &a, T b) {
  return a > b ? a = b, 1 : 0;
}
template <class T>
inline bool chmax(T &a, T b) {
  return a < b ? a = b, 1 : 0;
}
int n, in[2002], k;
bool can(int tar) {
  int i, j;
  vector<int> dp(n + 1, n);
  dp[0] = 0;
  for (i = 0; i < n; i++) {
    chmin(dp[i], i);
    for (j = 0; j < i; j++) {
      long long d = i - j;
      if (d * tar >= abs(in[i] - in[j])) {
        chmin(dp[i], dp[j] + (i - j - 1));
      }
    }
  }
  int res = 1 << 28;
  for (i = 0; i < n; i++) {
    chmin(res, dp[i] + (n - i - 1));
  }
  if (res <= k) return 1;
  return 0;
}
int main() {
  int i, j, tcc, tc = 1 << 28;
  for (tcc = 0; tcc < tc; tcc++) {
    n = getint(), k = getint();
    for (i = 0; i < n; i++) in[i] = getint();
    long long lo = 0;
    long long hi = 1e10;
    for (; lo <= hi;) {
      long long md = lo + hi >> 1;
      int ok = can(md);
      if (ok) {
        hi = md - 1;
      } else {
        lo = md + 1;
      }
    }
    cout << lo << endl;
  }
  return 0;
}
