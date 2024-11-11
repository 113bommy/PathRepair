#include <bits/stdc++.h>
int visited[100 * 1000 + 20] = {};
std::vector<int> g[100 * 1000 + 20];
const int p = 1000 * 1000 * 1000 + 7;
int dfs(int v) {
  visited[v] = 1;
  int sum = 1;
  for (int i = 0; i < g[v].size(); i++) {
    if (visited[g[v][i]]) continue;
    sum += dfs(g[v][i]);
  }
  return sum;
}
namespace miller {
unsigned long long int multiply(unsigned long long int a,
                                unsigned long long int b,
                                unsigned long long int p) {
  unsigned long long int ans = 0;
  a = a % p;
  b = b % p;
  if (a >> 32 == 0 && b >> 32 == 0) return (a * b) % p;
  if (b > a) {
    b = a ^ b;
    a = a ^ b;
    b = a ^ b;
  }
  for (; b != 0; b = b >> 1) {
    if (b & 1) ans = (ans + a) % p;
    a = (a << 1) % p;
  }
  return ans;
}
unsigned long long int power(unsigned long long int a, unsigned long long int b,
                             unsigned long long int p) {
  unsigned long long int ans = 1;
  for (; b != 0; b = b >> 1) {
    if (b & 1) ans = multiply(ans, a, p);
    a = multiply(a, a, p);
  }
  return ans;
}
int single_test(unsigned long long int a, unsigned long long int d,
                unsigned long long int p) {
  unsigned long long int m = power(a, d, p);
  if (m == 1 || m == p - 1) return 1;
  while (d != p - 1) {
    m = multiply(m, m, p);
    d = d << 1;
    if (m == 1) return 0;
    if (m == p - 1) return 1;
  }
  return 0;
}
int bruteforce(int n) {
  int m;
  if (n == 2) return 1;
  if (n % 2 == 0) return 0;
  for (m = 3; m * m <= n; m = m + 2) {
    if (n % m == 0) return 0;
  }
  return 1;
}
int prime(unsigned long long int p) {
  if (p < 1000) return bruteforce(p);
  if ((p % 2 && p % 5 && p % 7 && p % 11 && p % 13 && p % 17 && p % 19 &&
       p % 23) == 0)
    return 0;
  unsigned long long int d = p - 1;
  while (d % 2 == 0) d = d >> 1;
  unsigned long long int t = p;
  if (!single_test(2, d, p)) return 0;
  if (t >> 10 == 0) return 1;
  if (!single_test(3, d, p)) return 0;
  if (t >> 20 == 0) return 1;
  if (!single_test(5, d, p)) return 0;
  if (t >> 24 == 0) return 1;
  if (!single_test(7, d, p)) return 0;
  if (t >> 31 == 0) return 1;
  if (!single_test(11, d, p)) return 0;
  if (t >> 40 == 0) return 1;
  if (single_test(13, d, p) && single_test(17, d, p) && single_test(19, d, p) &&
      single_test(23, d, p))
    return 1;
  return 0;
}
}  // namespace miller
int main() {
  int n, k;
  std::cin >> n >> k;
  for (int i = 0; i < n - 1; i++) {
    int u, v, x;
    scanf("%d%d%d", &u, &v, &x);
    if (!x) {
      g[u].push_back(v);
      g[v].push_back(u);
    }
  }
  long long int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (!visited[i]) ans += miller::power(dfs(i), k, p);
  }
  ans = miller::power(n, k, p) - ans;
  ans = ans % p;
  ans = ans < 0 ? p - ans : ans;
  std::cout << ans << '\n';
  return 0;
}
