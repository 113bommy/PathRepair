#include <bits/stdc++.h>
using namespace std;
int n, m, tot, p;
long long ans;
int main(int argc, char **argv) {
  scanf("%d%d", &n, &m);
  ++n;
  p = n - m - 1;
  for (int i = m + 1; (i << 1) <= n; ++i)
    for (int j = m + 1; j < n - m; ++j) {
      tot = ((((n - i) << 1) + j) * i - j * n - 1) / (i + j);
      if (tot > p)
        tot = p;
      else if (tot < m)
        tot = m;
      ans += tot - m;
      if ((i << 1) != n) ans += tot - m;
    }
  printf("%I64d\n", ans * 3);
  return 0;
}
