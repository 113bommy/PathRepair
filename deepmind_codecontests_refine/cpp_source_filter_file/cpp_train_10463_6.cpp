#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int a[maxn], n;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  sort(a + 1, a + 1 + n);
  int ans = maxn;
  for (int i = 1; i + n / 2 <= n; i++) ans = min(ans, a[i + n / 2] - a[i]);
  printf("%d\n", ans);
}
