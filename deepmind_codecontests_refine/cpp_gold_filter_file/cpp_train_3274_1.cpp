#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> a, R;
vector<int> fact;
vector<vector<int> > dp, np;
double funcio(int x) {
  double num = 0;
  if (x % 2 == 0) num += pow(2, 0);
  if (x % 3 == 0) num += pow(2, 1);
  if (x % 5 == 0) num += pow(2, 2);
  if (x % 7 == 0) num += pow(2, 3);
  if (x % 11 == 0) num += pow(2, 4);
  if (x % 13 == 0) num += pow(2, 5);
  if (x % 17 == 0) num += pow(2, 6);
  if (x % 19 == 0) num += pow(2, 7);
  if (x % 23 == 0) num += pow(2, 8);
  if (x % 29 == 0) num += pow(2, 9);
  if (x % 31 == 0) num += pow(2, 10);
  if (x % 37 == 0) num += pow(2, 11);
  if (x % 43 == 0) num += pow(2, 12);
  if (x % 41 == 0) num += pow(2, 13);
  if (x % 45 == 0) num += pow(2, 14);
  if (x % 47 == 0) num += pow(2, 15);
  if (x % 53 == 0) num += pow(2, 16);
  return num;
}
int main() {
  cin >> n;
  a = vector<int>(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  fact = vector<int>(60);
  for (int i = 1; i < 60; ++i) fact[i] = int(funcio(i));
  dp = vector<vector<int> >(n + 2, vector<int>((1 << 17) + 2, 1000000));
  np = vector<vector<int> >(n + 2, vector<int>((1 << 17) + 2));
  for (int i = 0; i < ((1 << 17) + 2); ++i) dp[0][i] = 0;
  int minim = 10000000;
  int darrers;
  for (int i = 1; i <= n; i++) {
    for (int k = 1; k < 60; k++) {
      int x = (~fact[k]) & ((1 << 17) - 1);
      for (int s = x;; s = (s - 1) & x) {
        if (dp[i - 1][s] + abs(a[i - 1] - k) < dp[i][s | fact[k]]) {
          dp[i][s | fact[k]] = dp[i - 1][s] + abs(a[i - 1] - k);
          np[i][s | fact[k]] = k;
          if (i == n and dp[i][s | fact[k]] != -1 and
              dp[i][s | fact[k]] < minim) {
            minim = dp[i][s | fact[k]];
            darrers = s | fact[k];
          }
        }
        if (s == 0) break;
      }
    }
  }
  R = vector<int>(n + 1);
  for (int i = n; i > 0; --i) {
    R[i] = np[i][darrers];
    darrers = darrers & (~fact[R[i]]) & ((1 << 17) - 1);
  }
  for (int i = 1; i <= n; ++i) {
    if (i - 1) cout << ' ';
    cout << R[i];
  }
}
