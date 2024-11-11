#include <bits/stdc++.h>
using namespace std;
const int yuzu = 3e5;
pair<int, int> a[yuzu | 10];
int n, x1, x2;
int main() {
  int i;
  scanf("%d%d%d", &n, &x1, &x2);
  for (i = 1; i <= n; ++i) scanf("%d", &a[i].first), a[i].second = i;
  sort(a + 1, a + n + 1);
  for (i = n; i; --i) {
    int now = a[i].first, u = ((x1) + (now)-1) / (now), v = n - i + 1 - u;
    if (v >= 1 && ((x2) + (v)-1) / (v) <= a[n - v + 1].first) {
      printf("Yes\n%d%d\n", u, v);
      for (int k = i; k < n - v + 1; ++k) printf("%d ", a[k].second);
      puts("");
      for (int k = n - v + 1; k <= n; ++k) printf("%d ", a[k].second);
      return 0;
    }
    v = ((x2) + (now)-1) / (now), u = n - i + 1 - v;
    if (u >= 1 && ((x1) + (u)-1) / (u) <= a[n - u + 1].first) {
      printf("Yes\n%d%d\n", u, v);
      for (int k = n - u + 1; k <= n; ++k) printf("%d ", a[k].second);
      puts("");
      for (int k = i; k < n - u + 1; ++k) printf("%d ", a[k].second);
      return 0;
    }
  }
  puts("No");
}
