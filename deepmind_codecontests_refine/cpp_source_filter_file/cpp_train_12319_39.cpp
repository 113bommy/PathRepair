#include <bits/stdc++.h>
const double eps = 1e-9;
const int int_inf = 2000000000;
const long long i64_inf = 1000000000000000000ll;
const double pi = acos(-1.0);
using namespace std;
int d[(1 << 22) + 100];
int full = (1 << 22) - 1;
int n;
int a[100500];
int main() {
  memset(d, -1, sizeof(d));
  cin >> n;
  for (int i = 0; i < (int)n; i++) scanf("%d", &a[i]), d[full ^ a[i]] = a[i];
  for (int mask = (int)full + 10 - 1; mask >= 0; mask--) {
    if (d[mask] == -1) continue;
    for (int i = 0; i < (int)23; i++)
      if (mask & (1 << i)) d[mask - (1 << i)] = d[mask];
  }
  for (int i = 0; i < (int)n; i++) printf("%d ", d[a[i]]);
  return 0;
}
