#include <bits/stdc++.h>
using namespace std;
const int N = 300010;
const int MOD = 1e9 + 7;
int n;
int x[N];
long long sum[N];
long long po[N];
long long ans;
int main() {
  po[0] = 1;
  for (int i = (1); i < (N); i++) po[i] = po[i - 1] * 2 % MOD;
  scanf("%d", &n);
  for (int i = (0); i < (n); i++) scanf("%d", x + i);
  sort(x, x + n);
  long long now = x[0], p = 0;
  for (int i = (1); i < (n); i++) {
    p = (p + po[i - 1]) % MOD;
    ans = (ans + p * x[i] % MOD - now + MOD) % MOD;
    now = now * 2 % MOD + x[i];
  }
  printf("%lld\n", ans);
  return 0;
}
