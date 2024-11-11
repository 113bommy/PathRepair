#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
const int MAXN = 20010;
const int INF = 0x3f3f3f3f;
const double eps = 0.0000001;
const long long mod = 1e9 + 7;
int n, m, x, y, z, k, cnt, t, len, q;
int a[N], b[N];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) scanf("%d", &b[i]);
  sort(a + 1, a + n + 1);
  sort(b + 1, b + m + 1);
  printf("%d %d", a[n], b[m]);
}
