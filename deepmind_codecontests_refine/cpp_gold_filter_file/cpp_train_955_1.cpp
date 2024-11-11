#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, r;
    scanf("%d%d", &n, &r);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    sort(a + 1, a + 1 + n);
    int m = unique(a + 1, a + n + 1) - (a + 1);
    int cnt = 0;
    for (int i = m; i > 0; --i) {
      if (cnt * r >= a[i]) break;
      ++cnt;
    }
    printf("%d\n", cnt);
  }
  return 0;
}
