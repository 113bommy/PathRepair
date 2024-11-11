#include <bits/stdc++.h>
const int maxn = 1002, maxm = 1003;
int n, m, C[10], dp[maxm][maxn], len[maxn], od[maxn], tmp[maxn];
char A[maxm], B[maxn][maxm];
void fillRev(char *k, int l) {
  for (int i = 0; i * 2 < l; ++i) std::swap(k[i], k[l - i - 1]);
  for (int i = 0; i < maxm; ++i)
    if (!k[i]) k[i] = '0';
}
void init() {
  m = strlen(A);
  fillRev(A, m);
  for (int i = 0; i < n; ++i) {
    od[i] = i;
    len[i] = strlen(B[i]);
    fillRev(B[i], len[i]);
  }
}
void sortNext(int k) {
  for (int i = 0; i < n; ++i) tmp[od[i]] = i;
  auto cmp = [k](const int &u, const int &v) -> bool {
    return B[u][k] > B[v][k] || (B[u][k] == B[v][k] && tmp[u] < tmp[v]);
  };
  std::sort(od, od + n, cmp);
}
int calcCarry(int k, int j) {
  int c = 0;
  for (int i = 0; i < n; ++i)
    if (B[i][k] + j - '0' > 9) ++c;
  return c;
}
int calcDelta(int k, int j) {
  int d = 0;
  for (int i = 0; i < n; ++i)
    if (B[i][k] + j - '0' || k < std::max(m, len[i]))
      d += C[(B[i][k] + j - '0') % 10];
  return d;
}
void DP() {
  memset(dp, 0x80, sizeof(dp));
  {
    int l = 0, r = 9, c, d;
    if (!m) l = std::max(l, 1);
    if (A[0] != '?') l = r = A[0] - '0';
    for (int j = l; j <= r; ++j) {
      c = calcCarry(0, j);
      d = calcDelta(0, j);
      dp[0][c] = std::max(dp[0][c], d);
    }
    sortNext(0);
  }
  for (int k = 1, l, r, c, d; k < maxm; ++k) {
    l = 0;
    r = 9;
    if (k == m - 1) l = std::max(l, 1);
    if (A[k] != '?') l = r = A[k] - '0';
    for (int j = l; j <= r; ++j) {
      c = calcCarry(k, j);
      d = calcDelta(k, j);
      for (int i = 0, u; i <= n; ++i) {
        dp[k][c] = std::max(dp[k][c], dp[k - 1][i] + d);
        u = od[i];
        c -= bool(B[u][k] + j - '0' > 9);
        c += bool(B[u][k] + j + 1 - '0' > 9);
        d -= (B[u][k] + j - '0' || k < std::max(m, len[u]))
                 ? C[(B[u][k] + j - '0') % 10]
                 : 0;
        d += C[(B[u][k] + j + 1 - '0') % 10];
      }
    }
    sortNext(k);
  }
}
int main() {
  scanf("%s%d", A, &n);
  for (int i = 0; i < n; ++i) {
    scanf("%s", B[i]);
  }
  for (int i = 0; i < 10; ++i) {
    scanf("%d", C + i);
  }
  init();
  DP();
  printf("%d\n", dp[maxm - 1][0]);
  return 0;
}
