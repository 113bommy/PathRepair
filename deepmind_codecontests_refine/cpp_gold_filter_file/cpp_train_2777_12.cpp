#include <bits/stdc++.h>
using namespace std;
const int MaxN = 1e5;
const int Inf = 1 << 30;
long long ans, a, pos[20], vis[20], res, cnt, C[20][20], res1, cnt1;
void Dfs(int x) {
  if (x == 10) {
    res = 1;
    cnt = 0;
    for (int i = 0; i < 10; i++) cnt += vis[i];
    cnt1 = cnt;
    for (int i = 0; i < 10; i++) {
      res *= C[cnt][vis[i]];
      cnt -= vis[i];
    }
    if (vis[0] > 0) {
      res1 = C[cnt1 - 1][vis[0] - 1];
      cnt1 -= vis[0];
      for (int i = 1; i < 10; i++) {
        res1 *= C[cnt1][vis[i]];
        cnt1 -= vis[i];
      }
      res -= res1;
    }
    ans += res;
    return;
  }
  for (int i = 0; i <= pos[x]; i++) {
    vis[x] += i;
    Dfs(x + 1);
    vis[x] -= i;
  }
  return;
}
int main() {
  long long n;
  C[1][0] = 1;
  C[1][1] = 1;
  C[0][0] = 1;
  for (int i = 2; i <= 19; i++) {
    C[i][0] = 1;
    C[i][i] = 1;
    for (int j = 1; j <= i / 2; j++) {
      C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
      C[i][i - j] = C[i][j];
    }
  }
  while (~scanf("%I64d", &n)) {
    for (int i = 0; i < 10; i++) vis[i] = 0, pos[i] = 0;
    while (n) {
      a = n % 10;
      n /= 10;
      if (vis[a]) pos[a]++;
      vis[a] = 1;
    }
    ans = 0;
    Dfs(0);
    printf("%I64d\n", ans);
  }
  return 0;
}
