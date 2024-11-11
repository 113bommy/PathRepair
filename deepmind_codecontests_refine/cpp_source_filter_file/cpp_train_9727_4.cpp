#include <bits/stdc++.h>
using namespace std;
int num[1005][1005];
int mod;
int memo[1005][1005];
int ncr(int n, int r) {
  if (n == r)
    return 1;
  else if (r == 0)
    return 1;
  else if (memo[n][r] != -1)
    return memo[n][r];
  return memo[n][r] = (0LL + ncr(n - 1, r) + ncr(n - 1, r - 1)) % mod;
}
int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  for (int i = (1); i <= (k); i++) {
    int x, y, c;
    scanf("%d %d %d", &x, &y, &c);
    num[x][y] = c;
  }
  scanf("%d", &mod);
  if ((n + m) & 1) {
    printf("0\n");
    return 0;
  }
  int rc, id;
  bool done = 0;
  for (int i = (1); i <= (n); i++) {
    bool f = 1;
    for (int j = (1); j <= (m); j++) {
      f &= (num[i][j] == 0);
      if (!f) break;
    }
    if (f) {
      rc = 0;
      id = i;
      done = 1;
      break;
    }
  }
  if (!done) {
    for (int j = (1); j <= (m); j++) {
      bool f = 1;
      for (int i = (1); i <= (n); i++) {
        f &= (num[i][j] == 0);
        if (!f) break;
      }
      if (f) {
        rc = 1;
        id = j;
        break;
      }
    }
  }
  memset(memo, -1, sizeof(memo));
  int ans = 1;
  if (!rc) {
    for (int i = (1); i <= (n); i++) {
      if (i == id) continue;
      int sp = 0;
      bool add = 1;
      for (int j = (1); j <= (m); j++) {
        sp += (num[i][j] == 0);
        add ^= (num[i][j] == -1);
      }
      if (!sp && add) {
        printf("0\n");
        return 0;
      }
      int s = 0;
      for (int j = add; j <= sp; j += 2) {
        s = (0LL + s + ncr(sp, j)) % mod;
      }
      ans = 1LL * ans * s % mod;
    }
  } else {
    for (int i = (1); i <= (m); i++) {
      if (i == id) continue;
      int sp = 0;
      bool add = 1;
      for (int j = (1); j <= (m); j++) {
        sp += (num[j][i] == 0);
        add ^= (num[j][i] == -1);
      }
      if (!sp && add) {
        printf("0\n");
        return 0;
      }
      int s = 0;
      for (int j = add; j <= sp; j += 2) {
        s = (0LL + s + ncr(sp, j)) % mod;
      }
      ans = 1LL * ans * s % mod;
    }
  }
  printf("%d\n", ans);
  return 0;
}
