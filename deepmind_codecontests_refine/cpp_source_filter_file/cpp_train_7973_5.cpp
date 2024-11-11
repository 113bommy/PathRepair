#include <bits/stdc++.h>
using namespace std;
int n;
long long m, l, r, s1, s2, mid1, mid2;
long long getans(long long x) { return min(x * (x - 1) / 2, m - x) + m - x; }
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%I64d", &m);
    if (m == 1) {
      printf("0\n");
      continue;
    }
    if (m == 2) {
      printf("1\n");
      continue;
    }
    l = 1, r = m;
    while (l < r - 2) {
      mid1 = (l + r) >> 1;
      mid2 = (mid1 + r) >> 1;
      s1 = getans(mid1);
      s2 = getans(mid2);
      if (s1 < s2) {
        l = mid1;
      } else
        r = mid2;
    }
    cout << max(getans(l), max(getans(l + 1), getans(r)));
  }
  return 0;
}
