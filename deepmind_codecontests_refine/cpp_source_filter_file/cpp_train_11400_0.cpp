#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
int n, a[N], b[N], c[N], mx[N], gc[N];
int gcd(int a, int b) { return !b ? a : gcd(b, a % b); }
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 1; i < n; i++) gc[i] = gcd(i, n);
  long long ans = 0;
  for (int g = 1; g < n; g++)
    if (n % g == 0) {
      for (int i = 1; i <= n; i++) c[i] = c[i - 1] + (gc[i] == g);
      for (int i = 0; i < g; i++) mx[i] = a[i];
      for (int i = g; i < n; i++) mx[i % g] = max(mx[i % g], a[i]);
      for (int i = 0; i < n; i++) b[i] = b[i + n] = (mx[i % g] == a[i]);
      for (int i = n + n - 2; i >= 0; i--)
        if (b[i]) b[i] += b[i + 1];
      for (int i = 0; i < n; i++) ans += c[min(n - 1, b[i])];
    }
  printf("%lld", ans);
  return 0;
}
