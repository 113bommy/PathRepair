#include <bits/stdc++.h>
using namespace std;
int n, m;
long long k;
int ar[205];
long long dp[205][205];
long long stt(int idx, int op) {
  if (op == -1) return 0;
  if (idx == n + m - 1) {
    if (op == 0) return 1;
    return 0;
  }
  if (dp[idx][op] != -1) return dp[idx][op];
  long long sm = 0;
  if (ar[idx] != 0)
    sm = stt(idx + 1, op + ar[idx]);
  else {
    sm += stt(idx + 1, op + 1);
    if (sm > k)
      sm = k + 1;
    else
      sm += stt(idx + 1, op - 1);
  }
  if (sm > k) sm = k + 1;
  dp[idx][op] = sm;
  return sm;
}
struct port {
  int idx, c;
};
port cst[205];
bool cmp(port a, port b) { return a.c < b.c; }
int main() {
  scanf("%d%d%I64d", &n, &m, &k);
  int i, j, x;
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      cst[i + j].idx = i + j;
      ar[i + j] = 0;
      scanf("%d", &x);
      if (i == 0 || j == m - 1)
        cst[i + j].c = x;
      else
        cst[i + j].c = min(cst[i + j].c, x);
    }
  }
  sort(cst, cst + n + m - 1, cmp);
  int p = 0;
  long long v;
  for (p = 0; p < n + m - 1; p++) {
    memset(dp, -1, sizeof dp);
    ar[cst[p].idx] = 1;
    v = stt(0, 0);
    if (v < k) {
      ar[cst[p].idx] = -1;
      k -= v;
    } else
      ar[cst[p].idx] = 1;
  }
  int c = 9;
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++)
      if (ar[i + j] == 1)
        printf("(");
      else
        printf(")");
    printf("\n");
  }
}
