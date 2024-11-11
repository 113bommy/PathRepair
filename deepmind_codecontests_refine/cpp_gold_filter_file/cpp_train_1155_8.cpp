#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC optimize("no-stack-protector,fast-math")
using namespace std;
const int N = 1e6 + 5, M = 1e3 + 5, inf = 1e9;
int n, ar[M];
long long sum;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", ar + i);
    sum += 1ll * (ar[i] - 1) * (i + 1) + 1;
  }
  printf("%lld\n", sum);
  return 0;
}
