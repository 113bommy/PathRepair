#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:255000000")
using namespace std;
long double eps = 1e-7;
const int BASE = (int)1e9;
const long double PI = 3.1415926535897932384626433832795;
const int MOD = (int)1e9 + 7;
const int HMOD = (1 << 18) - 1;
const int N = 1 << 20;
const int INF = 1 << 30;
int n, m;
int s[110];
int pick[110];
int team[110];
int dp[20][1 << 20];
int F(int curAction, int mask) {
  if (curAction == m) return 0;
  int& res = dp[curAction][mask];
  if (res != 1 << 30) return res;
  if (team[curAction] == 1) res *= -1;
  int plus = 0;
  if (pick[curAction]) {
    for (int i = 0; i < min(n, 20); i++)
      if (!((1 << i) & mask)) {
        plus += s[i];
        res = F(curAction + 1, mask | (1 << i));
        break;
      }
  } else {
    for (int i = 0; i < min(n, 20); i++)
      if (!((1 << i) & mask)) {
        if (team[curAction] == 1)
          res = max(res, F(curAction + 1, mask | (1 << i)));
        else
          res = min(res, F(curAction + 1, mask | (1 << i)));
      }
  }
  return res + (team[curAction] == 1 ? 1 : -1) * plus;
}
int main() {
  for (int i = 0; i < 20; i++)
    for (int j = 0; j < 1 << 20; j++) dp[i][j] = 1 << 30;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &s[i]);
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    getchar();
    scanf("%c%d", &pick[i], &team[i]);
    pick[i] = pick[i] == 'p';
  }
  sort(s, s + n, greater<int>());
  printf("%d\n", F(0, 0));
  return 0;
}
