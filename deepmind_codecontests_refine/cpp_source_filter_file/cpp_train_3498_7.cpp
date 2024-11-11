#include <bits/stdc++.h>
using namespace std;
int sl;
int dp[8008], F[8008], P[8008][8008];
string s;
void pref(int x) {
  memset(F, 0, sizeof(F));
  string k;
  for (int i = x; i <= sl; i++) k += s[i];
  int sz = k.length();
  for (int i = 2; i <= sz; i++) {
    int j = F[i - 1];
    while (k[i - 1] != k[j] && j > 0) j = F[i];
    F[i] = (k[i - 1] == k[j] ? j + 1 : 0);
  }
  for (int i = 1; i <= sz; i++) P[i + x - 1][x] = F[i];
}
int ln(int x) {
  int ret = 0;
  while (x) x /= 10, ret++;
  return ret;
}
int main() {
  cin >> s;
  s = '#' + s;
  sl = s.length() - 1;
  for (int i = 1; i <= sl; i++) pref(i);
  for (int i = 1; i <= sl; i++) dp[i] = 1000000007;
  for (int i = 1; i <= sl; i++) {
    for (int h = 1; h <= i; h++) {
      int l = i - h + 1;
      dp[i] = min(dp[i], dp[h - 1] + (l % (l - P[i][h]) == 0
                                          ? l - P[i][h] + ln(l / (l - P[i][h]))
                                          : l + 1));
    }
  }
  printf("%d", dp[sl]);
}
