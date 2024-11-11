#include <bits/stdc++.h>
using namespace std;
template <class T>
inline bool fs(T &x) {
  int c = getchar();
  int sgn = 1;
  while (~c && c < '0' || c > '9') {
    if (c == '-') sgn = -1;
    c = getchar();
  }
  for (x = 0; ~c && '0' <= c && c <= '9'; c = getchar()) x = x * 10 + c - '0';
  x *= sgn;
  return ~c;
}
int ara[6];
int dp[4005][4];
int solv(int n, int cnt) {
  if (n < 0) return INT_MIN;
  if (n == 0) return 0;
  if (dp[n][cnt] != -1) return dp[n][cnt];
  int mx = -100000;
  for (int i = 0; i < 3; i++) mx = max(mx, solv(n - ara[i], i) + 1);
  return dp[n][cnt] = mx;
}
int main() {
  int n;
  fs(n);
  fs(ara[0]);
  fs(ara[1]);
  fs(ara[2]);
  memset(dp, -1, sizeof(dp));
  cout << solv(n, 0) << endl;
  return 0;
}
