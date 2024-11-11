#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const int MAX = 505;
int N, K, st[MAX][10];
int a[MAX], b[MAX];
long long pd[MAX][MAX];
void SparseTable() {
  for (int j = (0); j < (10); j++)
    for (int i = 1; (i + (1 << j) - 1) <= N; i++)
      st[i][j] = j ? min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]) : a[i];
}
int query(int l, int r, int k) {
  return min(st[l][k], st[r - (1 << k) + 1][k]);
}
long long solve(int i, int j) {
  if (i > j) return 1;
  if (pd[i][j] != -1) return pd[i][j];
  int m = b[query(i, j, log2(j - i + 1))];
  int left = 0, right = 0;
  for (int l = (i); l <= (m); l++)
    left = (left + solve(i, l - 1) * solve(l, m - 1)) % mod;
  for (int r = (m); r <= (j); r++)
    right = (right + solve(m + 1, r) * solve(r + 1, j)) % mod;
  return pd[i][j] = (left * right) % mod;
}
int main(int argc, char** argv) {
  scanf("%d%d", &N, &K);
  for (int i = (1); i <= (N); i++) scanf("%d", a + i);
  for (int i = (1); i <= (N); i++) b[a[i]] = i;
  SparseTable();
  memset(pd, -1, sizeof pd);
  printf("%I64d\n", solve(1, N));
  return 0;
}
