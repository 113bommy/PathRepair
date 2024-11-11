#include <bits/stdc++.h>
using namespace std;
int mi[] = {0, -1, 0, 1, -1, 1, 1, -1};
int mj[] = {1, 0, -1, 0, 1, 1, -1, -1};
int n1[50];
int n2[50];
long long dp[50][500][2][2];
bool memo[50][500][2][2];
int n;
long long solve(int i, int s, bool f1, bool f2) {
  if (i == n) return (s == 0 && f1 && f2);
  if (memo[i][s][f1][f2]) return dp[i][s][f1][f2];
  long long &ret = dp[i][s][f1][f2] = 0;
  for (int j = 0; j < 2; j++)
    for (int k = 0; k < 2; k++)
      if ((k + j + s) % 2 == n1[i] && (k ^ j) == n2[i])
        ret += solve(i + 1, (k + j + s) / 2, f1 || j, f2 || k);
  memo[i][s][f1][f2] = true;
  return ret;
}
void init() {
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  return;
}
int main() {
  long long x, y;
  scanf("%lld %lld", &x, &y);
  int t1 = 0;
  int t2 = 0;
  while (x) {
    n1[t1++] = x % 2;
    x /= 2;
  }
  while (y) {
    n2[t2++] = y % 2;
    y /= 2;
  }
  n = max(t1, t2);
  printf("%d\n", solve(0, 0, 0, 0));
  return 0;
}
