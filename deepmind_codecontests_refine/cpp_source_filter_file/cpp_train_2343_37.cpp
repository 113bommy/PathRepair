#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
const int M = 1e6 + 7;
const int lim = 1e6;
const int P = 998244353;
const int inf = 0x3f3f3f3f;
int n, k, mx, x, y, ans, mi = inf;
int a[N], b[N];
map<long long, int> mp;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    b[a[i]]++;
  }
  sort(a + 1, a + 1 + n);
  for (int i = 0; i <= lim; i++) {
    b[i + 1] += b[i] / 2;
    if (b[i] % 2 == 1) ans++;
  }
  printf("%d\n", ans);
  return 0;
}
