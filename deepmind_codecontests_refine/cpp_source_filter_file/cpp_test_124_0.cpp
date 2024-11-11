#include <bits/stdc++.h>
using namespace std;
std::mt19937 rnd(
    (int)std::chrono::steady_clock::now().time_since_epoch().count());
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
const int MAXN = 2000;
const int MOD = 1000000007;
void inc(int &a, int b) {
  if ((a += b) >= MOD) a -= MOD;
}
int n;
char s[MAXN + 1];
char t[MAXN + 1];
int a[MAXN];
int b[MAXN];
int pref[MAXN + 1][2 * MAXN + 1];
int suff[MAXN + 1][2 * MAXN + 1];
int solve() {
  for (int i = (0); i < (n); ++i) a[i] = s[i] == '?' ? -1 : s[i] - '0';
  for (int i = (0); i < (n); ++i) b[i] = t[i] == '?' ? -1 : t[i] - '0';
  for (int i = (0); i < (n); ++i)
    if (i % 2 == 1 && a[i] != -1) a[i] = 1 - a[i];
  for (int i = (0); i < (n); ++i)
    if (i % 2 == 1 && b[i] != -1) b[i] = 1 - b[i];
  for (int i = (0); i <= (n); ++i)
    for (int bal = (-n); bal <= (+n); ++bal) pref[i][n + bal] = 0;
  inc(pref[0][n + 0], 1);
  for (int i = (0); i < (n); ++i)
    for (int bal = (-n); bal <= (+n); ++bal) {
      int cur = pref[i][n + bal];
      if (cur == 0) continue;
      for (int x = (0); x < (2); ++x)
        for (int y = (0); y < (2); ++y) {
          if (a[i] != -1 && a[i] != x) continue;
          if (b[i] != -1 && b[i] != y) continue;
          int nbal = bal + x - y;
          inc(pref[i + 1][n + nbal], cur);
        }
    }
  for (int i = (0); i <= (n); ++i)
    for (int bal = (-n); bal <= (+n); ++bal) suff[i][n + bal] = 0;
  inc(suff[n][n + 0], 1);
  for (int i = n - 1; i >= 0; --i)
    for (int bal = (-n); bal <= (+n); ++bal) {
      int cur = suff[i + 1][n + bal];
      if (cur == 0) continue;
      for (int x = (0); x < (2); ++x)
        for (int y = (0); y < (2); ++y) {
          if (a[i] != -1 && a[i] != x) continue;
          if (b[i] != -1 && b[i] != y) continue;
          int nbal = bal - (x - y);
          inc(suff[i][n + nbal], cur);
        }
    }
  int ret = 0;
  for (int i = (0); i < (n); ++i)
    for (int x = (0); x < (2); ++x)
      for (int y = (0); y < (2); ++y) {
        if (a[i] != -1 && a[i] != x) continue;
        if (b[i] != -1 && b[i] != y) continue;
        if (x == y) continue;
        for (int bal = (-n); bal <= (+n); ++bal) {
          int ways = pref[i][n + bal];
          if (ways == 0) continue;
          int nbal = bal + x - y;
          ways = (long long)ways * suff[i + 1][n + nbal];
          int sgn = abs(nbal) > abs(bal) ? MOD - 1 : +1;
          ret = (ret + (long long)sgn * ways % MOD * i) % MOD;
        }
      }
  return ret;
}
void run() {
  scanf("%d", &n);
  scanf("%s", s);
  scanf("%s", t);
  printf("%d\n", solve());
}
int main() {
  int ncase;
  scanf("%d", &ncase);
  for (int i = (1); i <= (ncase); ++i) run();
  return 0;
}
