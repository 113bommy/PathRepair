#include <bits/stdc++.h>
long long int powmod(int bs, int exp) {
  if (exp == 0) return 1;
  if (exp == 1) return bs % 1000000007;
  if (exp == 2) return (bs * bs) % 1000000007;
  if (exp % 2 == 0) {
    long long int hf = powmod(bs, exp / 2) % 1000000007;
    return (hf * hf) % 1000000007;
  }
  if (exp % 2 == 1) {
    long long int hf = powmod(bs, exp / 2) % 1000000007;
    return (((hf * hf) % 1000000007) * bs) % 1000000007;
  }
}
int main() {
  long long int ans;
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  if (k == 1)
    ans = powmod(m, n);
  else if (k == n)
    ans = powmod(m, (n + 1) / 2);
  else if (k % 2 == 1)
    ans = m * m;
  else
    ans = m;
  if (k > n) ans = powmod(m, n);
  printf("%I64d\n", ans);
  return 0;
}
