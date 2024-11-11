#include <bits/stdc++.h>
using namespace std;
char b[3][11000], bb[3][11000];
int n;
int dp[11000][1 << 3];
bool okH(int j, int i) { return b[i][j] != 'X' && b[i][j + 1] != 'X'; }
bool okV(int j, int i) { return b[i][j] != 'X' && b[i + 1][j] != 'X'; }
int solve(int i, int mask) {
  if (i == n) return mask == 0;
  int &ret = dp[i][mask];
  if (ret != -1) return ret;
  int nmask = mask;
  if (b[0][i] == 'X') nmask |= 1;
  if (b[1][i] == 'X') nmask |= 2;
  if (b[2][i] == 'X') nmask |= 4;
  if (nmask != mask) return ret = solve(i, nmask);
  long long retu = 0;
  if (mask == 7) return ret = solve(i + 1, 0);
  if (mask == 0) {
    if (okH(i, 0) && okH(i, 1) && okH(i, 2)) retu += solve(i + 1, 7);
    if (okH(i, 0) && okV(i, 1)) retu += solve(i + 1, 1);
    if (okH(i, 2) && okV(i, 0)) retu += solve(i + 1, 4);
  } else {
    if (__builtin_popcount(mask) == 2) {
      int k = mask ^ 7;
      if (k == 1)
        k = 0;
      else if (k == 2)
        k = 1;
      else
        k = 2;
      if (okH(i, k)) retu += solve(i + 1, mask ^ 7);
    } else {
      if (mask != 2 && okV(i, 0 + (mask != 4))) retu += solve(i + 1, 0);
      int k1, k2;
      k1 = 0;
      k2 = 1;
      if (mask == 1)
        k1 = 2;
      else if (mask == 2)
        k2 = 2;
      if (okH(i, k1) && okH(i, k2)) retu += solve(i + 1, mask ^ 7);
    }
  }
  return ret = (retu % 1000000007);
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < 3; i++) scanf("%s", b[i]);
  int x, y;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < n; j++)
      if (b[i][j] == 'O') x = i, y = j;
  memcpy(bb, b, sizeof b);
  int ans = 0;
  for (int i = 1; i <= (1 << 4) - 1; i++) {
    memcpy(b, bb, sizeof bb);
    if (i & 1) {
      if (x != 2) continue;
      if (b[0][y] == 'B' || b[1][y] == 'B') continue;
      b[0][y] = b[1][y] = b[2][y] = 'X';
    }
    if (i & 2) {
      if (x != 0) continue;
      if (b[1][y] == 'B' || b[2][y] == 'B') continue;
      b[0][y] = b[1][y] = b[2][y] = 'X';
    }
    if (i & 4) {
      if (y < 2) continue;
      if (b[x][y - 1] == 'B' || b[x][y - 2] == 'B') continue;
      b[x][y] = b[x][y - 1] = b[x][y - 2] = 'X';
    }
    if (i & 8) {
      if (y + 2 >= n) continue;
      if (b[x][y + 1] == 'B' || b[x][y + 2] == 'B') continue;
      b[x][y] = b[x][y + 1] = b[x][y + 2] = 'X';
    }
    memset(dp, -1, sizeof dp);
    if (__builtin_popcount(i) % 2)
      ans += solve(0, 0);
    else
      ans -= solve(0, 0);
    ans = ((ans % 1000000007) + 1000000007) % 1000000007;
  }
  printf("%d", ans);
  printf("\n");
}
