#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, i, mod = 1000000007, L = 0;
  scanf("%lld", &n);
  long long int degree[200002];
  memset(degree, 0, 200002);
  for (i = 1; i < n; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    a--;
    b--;
    degree[a]++;
    degree[b]++;
  }
  long long int temp = 1, ans = 0;
  for (i = 0; i < n; i++) {
    if (degree[i] != 1) temp = (2 * temp) % mod;
  }
  for (i = 0; i < n; i++) {
    if (degree[i] == 1)
      ans += 2 * temp;
    else
      ans += temp;
  }
  printf("%lld\n", ans % mod);
  return 0;
}
