#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int n;
int a[100009], x[100009], cnt[100009];
int main() {
  while (~scanf("%d", &n)) {
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    sort(a, a + n);
    int ans = 0, r = 0;
    for (int i = 0; i < n; i++) {
      while (r < n && a[r] <= a[i]) r++;
      if (r < n) ans++;
    }
    printf("%d\n", ans);
  }
  return 0;
}
