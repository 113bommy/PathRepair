#include <bits/stdc++.h>
using namespace std;
const int Nmax = 512, PNmax = 20 * 512, MOD = 1000000007;
int n, in[Nmax], ps[PNmax][2], pn = 0;
void insert(int p, int num) {
  for (int i = 0; i < pn; ++i) {
    if (ps[i][0] == p) ps[i][1] += num, p = 0;
  }
  if (p) {
    ps[pn][0] = p, ps[pn][1] = num;
    pn++;
  }
}
const int PMmax = Nmax * 33;
long long f[Nmax][PMmax];
void calcuf() {
  for (int i = 0; i < PMmax; ++i) f[1][i] = 1;
  for (int i = 2; i <= n; ++i) {
    f[i][0] = 1;
    long long sum = 1;
    for (int j = 1; j < PMmax; ++j) {
      sum = (sum + f[i - 1][j]) % MOD;
      f[i][j] = sum;
    }
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", in + i);
  calcuf();
  for (int i = 0; i < n; ++i) {
    int x = in[i];
    int up = (int)sqrt(x);
    for (int j = 2; j <= up && j < x; ++j) {
      if (x % j) continue;
      int num = 0;
      while (!(x % j)) {
        x /= j;
        num++;
      }
      insert(j, num);
    }
    if (x > 1) insert(x, 1);
  }
  long long re = 1;
  for (int i = 0; i < pn; ++i) re = (re * f[n][ps[i][1]]) % MOD;
  if (re < 0) re += MOD;
  printf("%I64d\n", re);
  return 0;
}
