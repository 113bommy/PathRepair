#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 1, oo = 1e9, MOD = 1073741824;
int a, b, c;
long long sum, d[N];
int main() {
  for (int i = 1; i <= N; i++)
    for (int j = i; j <= N; j += i) d[j]++;
  scanf("%d%d%d", &a, &b, &c);
  for (int i = 1; i <= a; i++)
    for (int j = 1; j <= b; j++)
      for (int k = 1; k <= c; k++) sum = sum % MOD + d[i * j * k] % MOD;
  printf("%lld\n", sum);
  return 0;
}
