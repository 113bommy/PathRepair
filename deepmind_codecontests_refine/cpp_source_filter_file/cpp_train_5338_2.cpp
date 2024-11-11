#include <bits/stdc++.h>
using namespace std;
int a[100005], b[100005];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  sort(a + 1, a + 1 + n);
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (i % 2 == 0) b[i] = a[++cnt];
  }
  for (int i = 1; i <= n; i++) {
    if (i % 2 == 1) b[i] = a[++cnt];
  }
  printf("%d\n", n / 2);
  for (int i = 1; i <= n; i++) printf("%d ", b[i]);
  return 0;
}
