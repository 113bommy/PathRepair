#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 1, M = 1e9 + 7;
int n, m, fact[N] = {1}, inv[N];
int power(int base, int to) {
  int ret = 1;
  while (to) {
    if (to & 1) ret = ret * 1LL * base % M;
    to >>= 1;
    base = base * 1LL * base % M;
  }
  return ret;
}
void add(int &a, int b) {
  a += b;
  if (a >= M) a -= M;
}
int choose(int n, int k) {
  return (fact[n] * 1LL * inv[k] % M) * inv[n - k] % M;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i < N; i++) fact[i] = fact[i - 1] * 1LL * i % M;
  inv[N - 1] = power(fact[N - 1], M - 2);
  for (int i = N - 1; i; i--) inv[i - 1] = inv[i] * 1LL * i % M;
  int ans = power(m, n);
  for (int i = 1; i <= n; i++) {
    int temp = power(m, i) * 1LL * power(m - 1, n - i) % M;
    temp = temp * 1LL * choose(n, i - 1) % M;
    add(ans, temp);
  }
  printf("%d\n", ans);
}
