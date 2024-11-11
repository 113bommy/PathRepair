#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int vis[N], n;
int a[] = {0, 4, 10, 20, 35, 56, 83, 116, 155, 198, 244, 292};
int main() {
  cin >> n;
  if (n <= 10) {
    printf("%d\n", a[n]);
    return 0;
  }
  long long ans = 292 + 1ll * (n - 11) * 49;
  printf("%lld\n", ans);
}
