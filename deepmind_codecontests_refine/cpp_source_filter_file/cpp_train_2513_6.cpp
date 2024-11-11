#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int maxn = 65005;
const int N = 5005, M = 2 * 30005;
char second[maxn];
int main() {
  int n;
  scanf("%d", &n);
  scanf("%s", &second);
  long long ans = 0;
  for (int i = 0; i < n; ++i)
    if (!((second[i] - '0') & 1)) ans += i * 1ll;
  printf("%lld\n", ans);
  return 0;
}
