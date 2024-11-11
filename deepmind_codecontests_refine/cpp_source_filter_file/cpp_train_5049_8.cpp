#include <bits/stdc++.h>
using namespace std;
int n, k, t[200010];
long long int prefix[200010], suffix[200010], x, b;
int main() {
  scanf("%d %d %I64d", &n, &k, &x);
  b = x;
  for (int i = 1; i <= n; i++) scanf("%d", &t[i]);
  for (int i = 2; i <= k; i++) x = x * b;
  for (int i = 1; i <= n; i++) prefix[i] = prefix[i - 1] | t[i];
  for (int i = n; i >= 1; i--) suffix[i] = suffix[i + 1] | t[i];
  long long int sol = 0;
  for (int i = 1; i <= n; i++)
    sol = max(sol, prefix[i - 1] | (1LL * t[i] * x) | suffix[i + 1]);
  printf("%d", sol);
  return 0;
}
