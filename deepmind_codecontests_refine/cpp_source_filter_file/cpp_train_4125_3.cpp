#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000050, maxm = 120, mod = 1e9 + 7;
int n, l, m, c[maxn], st[maxn], en[maxn], ans;
int cc[maxm], ce[maxm];
int f0[maxm], trans[maxm][maxm], f1[maxm];
int tmp[maxm][maxm];
void Add(int &x, int k) { (x += k) >= mod ? x -= k : x; }
void Mul(int *num1, int *num2, int *ret, int a, int b, int c) {
  int i, j, k;
  for (i = 0; i < a; i++)
    for (j = 0; j < c; j++) {
      tmp[i][j] = 0;
      for (k = 0; k < b; k++)
        Add(tmp[i][j], 1LL * num1[i * maxm + k] * num2[k * maxm + j] % mod);
    }
  for (i = 0; i < a; i++)
    for (j = 0; j < c; j++) ret[i * maxm + j] = tmp[i][j];
}
void Pow(int *num, int k, int a) {
  int i, j, ret[maxm * maxm];
  for (i = 0; i < a; i++)
    for (j = 0; j < a; j++) ret[i * maxm + j] = (i == j);
  for (; k; k >>= 1) {
    if (k & 1) Mul(ret, num, ret, a, a, a);
    Mul(num, num, num, a, a, a);
  }
  for (i = 0; i < a; i++)
    for (j = 0; j < a; j++) num[i * maxm + j] = ret[i * maxm + j];
}
int main() {
  int i, j, k;
  scanf("%d%d%d", &n, &l, &m);
  for (i = 0; i < n; i++) scanf("%d", &st[i]), f0[st[i] % m]++;
  for (i = 0; i < n; i++) scanf("%d", &c[i]), cc[c[i] % m]++;
  for (i = 0; i < n; i++) scanf("%d", &en[i]), ce[(en[i] + c[i]) % m]++;
  for (i = 0; i < m; i++)
    for (j = 0; j < m; j++) trans[i][j] = cc[(j - i + m) % m];
  Pow((int *)trans, l - 2, m);
  Mul(f0, (int *)trans, f1, 1, m, m);
  for (k = 0; k < m; k++) Add(ans, 1LL * f1[(m - k) % m] * ce[k] % mod);
  printf("%d\n", ans);
  return 0;
}
