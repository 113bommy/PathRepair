#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int v[1000010], fact[1000010];
int rid_put(int a, int b) {
  int sol = 1;
  for (int i = 1; i <= b; i <<= 1) {
    if (i & b) sol = (1LL * sol * a) % mod;
    a = (1LL * a * a) % mod;
  }
  return sol;
}
int main() {
  int n, sol = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &v[i]);
  fact[0] = 1;
  for (int i = 1; i <= n; i++) fact[i] = (1LL * fact[i - 1] * i) % mod;
  sort(v + 1, v + n + 1);
  int cnt = 0;
  v[0] = 1e9 + 1;
  for (int i = 1; i <= n; i++) {
    if (v[i] == v[n]) continue;
    if (v[i - 1] < v[i]) cnt = i - 1;
    int nr = 1LL * fact[n] * rid_put(n - cnt, mod - 2) % mod;
    sol = (sol + (1LL * v[i] * nr) % mod) % mod;
  }
  printf("%d", sol);
  return 0;
}
