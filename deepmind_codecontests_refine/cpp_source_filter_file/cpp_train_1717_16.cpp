#include <bits/stdc++.h>
using namespace std;
long long modd;
long long n, l, k;
long long fum[][2] = {{0, 1}, {1, 1}};
void mul(long long a[][2], long long b[][2]) {
  long long ret[2][2];
  memset(ret, 0, sizeof(ret));
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
      for (int k = 0; k < 2; k++)
        ret[i][j] = (ret[i][j] + a[i][k] % modd * b[k][j] % modd) % modd;
  memcpy(a, ret, sizeof(ret));
}
void po(long long base[][2], long long n) {
  while (n) {
    if (1 & n) mul(base, fum);
    mul(fum, fum);
    n /= 2;
  }
}
long long go(long long a, long long b) {
  if (!b) return 1;
  if (b == 1) return a;
  long long ret = go(a, b / 2);
  long long sol = ret % modd * ret % modd;
  sol %= modd;
  if (b % 2) return (sol * a) % modd;
  return sol;
}
int main() {
  scanf("%lld", &n);
  scanf("%lld", &k);
  scanf("%lld", &l);
  scanf("%lld", &modd);
  long long base[][2] = {{1, 0}, {0, 1}};
  po(base, n - 1);
  long long sol = (base[0][0] * 2 + base[0][1] * 3) % modd;
  long long id = 0;
  long long ans = 1;
  for (int i = 0; i < 61; i++) {
    if ((1ll << i) & k)
      if (i >= l) {
        ans = 0;
        break;
      }
    if (i < l) {
      if ((1ll << i) & k) {
        ans = (ans * (go(2, n) - sol)) % modd;
        id = i;
      } else
        ans = (ans * (sol)) % modd;
    }
  }
  for (long long i = 61; i < min((int)l, 65); i++) ans = (ans * (sol)) % modd;
  while (ans < 0) ans += modd;
  printf("%lld\n", ans);
}
