#include <bits/stdc++.h>
using namespace std;
long long dp[800][800][4][4];
char buff[800];
int nxt[800];
int len;
long long sum(long long a, long long b) {
  return (a % 1000000007 + b % 1000000007) % 1000000007;
}
long long mult(long long a, long long b) {
  return (sum(a, 0) * sum(b, 0)) % 1000000007;
}
long long f(int bgn, int end, int banB, int banE) {
  long long& ans = dp[bgn][end][banB][banE];
  if (ans != -1) return ans;
  if (bgn > end) return ans = 0;
  if (bgn == end - 1) {
    if (banB == banE and banB == 0) return ans = 4;
    if (banB == 0 or banE == 0) return ans = 3;
    return ans = 2;
  }
  bool hasNext = end != nxt[bgn];
  bool single = nxt[bgn] == bgn + 1;
  int next = nxt[bgn];
  ans = 0;
  for (int color = 1; color < 3; color++) {
    ans = banB == color
              ? ans
              : sum(ans, mult(single ? 1 : f(bgn + 1, next - 1, color, 0),
                              hasNext ? f(next + 1, end, 0, banE) : 0));
    ans = !hasNext and (banE == color)
              ? ans
              : sum(ans, mult(single ? 1 : f(bgn + 1, next - 1, 0, color),
                              hasNext ? f(next + 1, end, color, banE) : 0));
  }
  return ans;
}
int solve() {
  memset(nxt, -1, sizeof nxt);
  for (int i = 0, j, lvl; buff[i]; i++)
    if (buff[i] == '(') {
      for (j = i + 1, lvl = 1; lvl; ++j) {
        lvl += buff[j] == '(' ? 1 : -1;
        if (lvl == 0) break;
      }
      nxt[i] = j;
    }
  memset(dp, -1, sizeof dp);
  return f(0, len - 1, 0, 0);
}
int main() {
  scanf("%s", buff);
  int lvl = 0;
  len = strlen(buff);
  for (int i = 0; buff[i]; i++) {
    lvl += buff[i] == '(' ? 1 : -1;
    if (lvl < 0) break;
  }
  if (lvl < 0)
    printf("0\n");
  else {
    long long ans = solve();
    cout << ans << endl;
  }
  return 0;
}
