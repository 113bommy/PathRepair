#include <bits/stdc++.h>
using namespace std;
int n;
long long res;
int main() {
  scanf("%d", &n);
  for (int i = 2; i < n; ++i) res += 1ll * (i + 1) * i;
  printf("%lld\n", res);
  return 0;
}
