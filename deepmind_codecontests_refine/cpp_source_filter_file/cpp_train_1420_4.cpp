#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e3 + 5;
int ans, n, a[maxn], p, last;
int main() {
  scanf("%d", &n), ans = 1;
  for (register int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  sort(a + 1, a + n + 1);
  for (register int i = 1; i <= n; ++i) {
    if (last == a[i])
      ++p;
    else
      p = 1;
    last = a[i];
    ans = max(ans, p);
  }
  printf("%d", p);
  return 0;
}
