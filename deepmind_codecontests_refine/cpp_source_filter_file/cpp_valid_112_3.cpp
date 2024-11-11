#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a[3], m;
    scanf("%d%d%d%d", &a[0], &a[1], &a[2], &m);
    sort(a, a + 2);
    if (m >= max(0, a[2] - 1 - a[0] - a[1]) &&
        m <= max(a[0] - 1, 0) + max(a[1] - 1, 0) + max(a[2] - 1, 0))
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}
