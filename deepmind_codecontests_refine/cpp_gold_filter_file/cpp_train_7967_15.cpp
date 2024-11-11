#include <bits/stdc++.h>
using namespace std;
const long long P = 1000000007;
long long f1[1000010], f2[1000010], ans;
int n, m;
int main() {
  scanf("%d%d", &n, &m);
  int i;
  for (f1[0] = f2[0] = i = 1; i <= n; i++)
    f1[i] = f1[i - 1] * m % P, f2[i] = f2[i - 1] * (m + m - 1) % P;
  for (ans = f1[n], i = 1; i <= n; i++)
    ans = (ans + f1[n - i + 1] * f2[i - 1]) % P;
  printf("%lld", ans);
  return 0;
}
