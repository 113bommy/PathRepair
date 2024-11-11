#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline bool checkmin(T &a, const T &b) {
  return a > b ? a = b, 1 : 0;
}
template <typename T>
inline bool checkmax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}
const int MOD = 1000000007;
const int MAXN = 3000 + 10;
int dp[MAXN][MAXN][2], k;
char l[MAXN], r[MAXN];
void update(int &a, const int &b) {
  a += b;
  if (a >= MOD) a %= MOD;
}
int cal(int l, int d, int h) {
  int &ans = dp[l][d][h];
  if (ans != -1) return ans;
  if (l == 0) return ans = h;
  ans = 0;
  for (int i = 0; i < (10); ++i) {
    if (i == 4 || i == 7)
      update(ans, cal(l - 1, 1, h | (d <= k)));
    else
      update(ans, cal(l - 1, d + 1, h));
  }
  return ans;
}
int solve(char s[]) {
  int ans = 0, d = k + 1, h = 0, n = strlen(s);
  for (int i = 0; i < (n); ++i) {
    for (int j = 0; j < (s[i] - '0'); ++j) {
      if (j == 4 || j == 7)
        update(ans, cal(n - i - 1, 1, h | (d <= k)));
      else
        update(ans, cal(n - i - 1, d + 1, h));
    }
    if (s[i] == '4' || s[i] == '7') {
      h |= (d <= k);
      d = 1;
    } else
      ++d;
  }
  return ans;
}
int check(char s[], int d = k + 1) {
  if (*s == 0) return 0;
  if (*s == '4' || *s == '7') return d <= k || check(s + 1, 1);
  return check(s + 1, d + 1);
}
int main() {
  memset(dp, -1, sizeof(dp));
  int T;
  while (scanf("%d%d", &T, &k) != EOF) {
    while (T--) {
      scanf(" %s %s", l, r);
      int ans = (solve(r) - solve(l) + check(r) + MOD) % MOD;
      printf("%d\n", ans);
    }
  }
  return 0;
}
