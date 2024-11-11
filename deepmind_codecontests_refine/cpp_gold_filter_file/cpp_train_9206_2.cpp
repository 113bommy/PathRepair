#include <bits/stdc++.h>
using namespace std;
long long int n, m, v[1005];
int main() {
  scanf("%lld %lld", &n, &m);
  for (long long int i = 1; i <= n; ++i) scanf("%d", &v[i]);
  long long int ans = 0;
  for (long long int i = 1; i <= m; ++i) {
    long long int a, b;
    scanf("%lld %lld", &a, &b);
    ans += min(v[a], v[b]);
  }
  printf("%lld", ans);
}
