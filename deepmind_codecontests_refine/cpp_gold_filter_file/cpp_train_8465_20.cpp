#include <bits/stdc++.h>
using namespace std;
const int MAX = 2000002;
const long long BASE = 137;
long long h[MAX];
long long v[MAX];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  v[n] = h[0] = 1;
  for (int i = 1; i < n; ++i) v[i + n] = h[i] = h[i - 1] * BASE;
  for (int i = 0; i < m; ++i) {
    int x, y;
    scanf("%d%d", &x, &y), --x, --y;
    v[x] += h[y], v[y] += h[x];
    v[x + n] += h[y], v[y + n] += h[x];
  }
  long long ret = 0;
  sort(v, v + 2 * n);
  for (int i = 0, j; i < 2 * n;) {
    j = i;
    while (i < 2 * n && v[i] == v[j]) ++i;
    ret += (i - j) * 1LL * (i - 1 - j) / 2;
  }
  printf("%I64d\n", ret);
  return 0;
}
