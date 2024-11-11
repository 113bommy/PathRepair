#include <bits/stdc++.h>
using namespace std;
const long long inf = 1000000007;
long long mod(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a % inf;
    b >>= 1;
    a = a * a % inf;
  }
  return res;
}
long long f[1100000], rev[1100000];
long long cal(long long a, long long b) {
  return f[a] * mod(f[b] * f[a - b] % inf, inf - 2) % inf;
}
long long dfs(long long a, long long b, long long k) {
  if (a + b == 1) return k ^ a;
  if (k == 1 && a == 0) return 0;
  if (k == 1) return dfs(a - 1, b, 0);
  if (b == 0) return dfs(a - 1, b, 1);
  if (a == 0) return 1;
  return (cal(a + b - 1, a) + dfs(a - 1, b, 1)) % inf;
}
int main() {
  f[0] = 1;
  for (int i = 1; i <= 1000005; ++i) f[i] = f[i - 1] * i % inf;
  long long n, m, k;
  cin >> n >> m >> k;
  cout << dfs(n, m, k) << endl;
  return 0;
}
