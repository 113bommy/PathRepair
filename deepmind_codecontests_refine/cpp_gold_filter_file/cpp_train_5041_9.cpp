#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:100000000000,100000000000")
using namespace std;
const double eps = 1E-9;
const double Exp = 2.718281828459045;
const double Pi = 3.1415926535897932;
const int NMAX = 300000 + 5;
const int MMAX = 26 + 5;
const int INF = 1000000000;
const int BASE = 1000000007;
template <typename T>
inline T abs(const T a) {
  if (a < 0) return -a;
  return a;
}
template <typename T>
inline T sqr(const T& a) {
  return a * a;
}
int main() {
  int n, i;
  int j;
  static int dp[NMAX][MMAX] = {0};
  int last[MMAX] = {0};
  int cur[MMAX];
  char s[NMAX];
  int mx;
  int k = 0;
  gets(s + 1);
  n = strlen(s + 1);
  mx = 0;
  for (i = 1; i <= n; i++) {
    s[i] -= 'a';
    if (0 == last[s[i]]) mx++;
    last[s[i]] = 1;
  }
  for (i = 0; i <= 'z' - 'a'; i++) last[i] = 0;
  for (i = 1; i <= n; i++) {
    last[s[i]] = i;
    for (j = 0; j <= 'z' - 'a' + 1; j++) cur[j] = last[j];
    sort(cur, cur + 'z' - 'a' + 2);
    reverse(cur, cur + 'z' - 'a' + 2);
    k = 0;
    for (j = 0; j <= 'z' - 'a'; j++) {
      dp[i][++k] = cur[j] - cur[j + 1];
      if (0 == cur[j + 1]) {
        break;
      }
    }
  }
  long long res[MMAX] = {0};
  for (j = 1; j <= mx; j++) {
    for (i = 1; i <= n; i++) {
      res[j] += dp[i][j];
    }
  }
  cout << mx << endl;
  for (j = 1; j <= mx; j++) cout << res[j] << endl;
  return 0;
}
