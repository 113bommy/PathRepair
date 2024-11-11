#include <bits/stdc++.h>
using namespace std;
bool check(int n, int pos) { return (bool)(n & (1 << pos)); }
int off(int n, int pos) { return n & ~(1 << pos); }
int x[32010], A[310], c[310], n;
int dp[310][310][600];
vector<int> p, factors[310];
void seive() {
  int i, j;
  for (i = 0; i < 32010; i++) x[i] = true;
  for (i = 2; i < 32010; i++) {
    if (x[i]) {
      p.push_back(i);
      for (j = i; j < 32010; j += i) x[j] = false;
    }
  }
}
void _primes(int i, int n) {
  int j;
  for (j = 0; j < p.size(); j++) {
    if (n % p[j] == 0) {
      factors[i].push_back(p[j]);
      while (n % p[j] == 0) n /= p[j];
    }
  }
  if (n > 1) factors[i].push_back(n);
}
int min_cost(int i, int base, int mask) {
  int a = 1 << 30, b = 1 << 30, j, temp = mask;
  if (mask == 0)
    return 0;
  else if (i == n + 1)
    return 1 << 30;
  if (dp[i][base][mask] != -1) return dp[i][base][mask];
  a = min_cost(i + 1, base, mask);
  if (base == 0)
    b = c[i] + min_cost(i + 1, i, (1 << factors[i].size()) - 1);
  else {
    for (j = 0; j < factors[base].size(); j++)
      if (A[i] % factors[base][j] != 0 && check(mask, j)) mask = off(mask, j);
    b = c[i] + min_cost(i + 1, i, mask);
  }
  return dp[i][base][temp] = (((a) < (b)) ? (a) : (b));
}
int main() {
  int i, j, k, temp;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%d", &A[i]);
  for (i = 1; i <= n; i++) scanf("%d", &c[i]);
  seive();
  for (i = 1; i <= n; i++) {
    _primes(i, A[i]);
  }
  for (i = 0; i < 310; i++)
    for (j = 0; j < 310; j++)
      for (k = 0; k < 600; k++) dp[i][j][k] = -1;
  k = min_cost(1, 0, 511);
  k == 1 << 30 ? printf("%d\n", -1) : printf("%d\n", k);
  return 0;
}
