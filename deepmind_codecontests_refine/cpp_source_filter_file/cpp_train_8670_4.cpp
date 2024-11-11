#include <bits/stdc++.h>
using namespace std;
bool lucky(int x) {
  while (x) {
    int d = x % 10;
    if (x != 4 && x != 7) return false;
    x /= 10;
  }
  return true;
}
int pm(int a, int e) {
  int r = 1;
  while (e) {
    if (e & 1) r = (1LL * r * a) % 1000000007;
    e >>= 1;
    a = (1LL * a * a) % 1000000007;
  }
  return r;
}
int inv(int a) { return pm(a, 1000000007 - 2); }
int fact[100005];
int comb(int n, int k) {
  if (k < 0 || k > n) return 0;
  return (1LL * fact[n] * inv((1LL * fact[k] * fact[n - k]) % 1000000007)) %
         1000000007;
}
map<int, int> w;
int f[100005];
int n, k, nl;
int main() {
  fact[0] = 1;
  for (int i = 1, to = 100005; i < to; ++i)
    fact[i] = (1LL * fact[i - 1] * i) % 1000000007;
  scanf("%d%d", &n, &k);
  for (int i = 0, to = n; i < to; ++i) {
    int x;
    scanf("%d", &x);
    if (lucky(x)) {
      w[x]++;
      nl++;
    }
  }
  f[0] = 1;
  for (map<int, int>::iterator it = w.begin(); it != w.end(); ++it) {
    int c = it->second;
    for (int i = k; i > 0; --i)
      f[i] += (1LL * f[i - 1] * c) % 1000000007, f[i] %= 1000000007;
  }
  int r = 0;
  for (int i = 0, to = k + 1; i < to; ++i) {
    r += (1LL * f[i] * comb(n - nl, k - i)) % 1000000007;
    r %= 1000000007;
  }
  printf("%d\n", r);
  return 0;
}
