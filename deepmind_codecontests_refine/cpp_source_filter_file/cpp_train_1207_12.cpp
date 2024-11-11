#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;
int a[maxn];
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  sort(a, a + n);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] / 2 <= k) {
      if (k < a[i]) k = a[i];
    } else {
      k *= 2;
      ans++;
      i--;
    }
  }
  printf("%d\n", ans);
}
