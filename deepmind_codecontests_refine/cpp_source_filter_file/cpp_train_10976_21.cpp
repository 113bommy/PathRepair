#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 1; i < n; i++) scanf("%d", &a[i]);
  sort(a, a + n);
  int ans = 0;
  for (int i = 0; i < n - 2; i += 3) {
    if (a[i + 2] + k > 5) break;
    ans++;
  }
  printf("%d\n", ans);
  return 0;
}
