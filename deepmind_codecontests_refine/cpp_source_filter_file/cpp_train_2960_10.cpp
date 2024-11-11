#include <bits/stdc++.h>
using namespace std;
const int N = 1000006;
int n, j, a[N], f[N], e;
long long dp[N], fac[N], ans, x, i, add, cur;
void Add(int x) {
  for (int i = x; i < N; i = (2 * i - (i & (i - 1)))) f[i]++;
}
int sum(int x) {
  int s = 0;
  while (x) s += f[x], x &= x - 1;
  return s;
}
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%d", &a[i]);
  fac[0] = 1;
  for (i = 1; i <= n; i++) fac[i] = (fac[i - 1] * i) % 1000000007;
  for (i = 2; i <= n; i++) {
    dp[i] = (dp[i - 1] * i) % 1000000007;
    x = ((i * (i - 1)) / 2) % 1000000007;
    dp[i] = (dp[i] + (x * fac[i - 1]) % 1000000007) % 1000000007;
  }
  for (i = 1; i <= n; i++) {
    e = sum(a[i] - 1);
    e = a[i] - 1 - e;
    cur = (e * dp[n - i]) % 1000000007;
    x = ((e * (e - 1)) / 2) % 1000000007;
    cur = (cur + (x * fac[n - i]) % 1000000007) % 1000000007;
    x = (e * add) % 1000000007;
    cur = (cur + (x * fac[n - i]) % 1000000007) % 1000000007;
    ans = (ans + cur) % 1000000007;
    add = (add + e) % 1000000007;
    Add(a[i]);
  }
  cout << (ans + add) % 1000000007 << endl;
}
