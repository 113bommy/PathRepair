#include <bits/stdc++.h>
using namespace std;
int n, a[1001], k;
int main() {
  scanf("%d%d", &n, &k);
  n = 2 * n + 1;
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (int i = 2; i < n; i += 2)
    if (k && a[i - 1] + 1 < a[i] && a[i] > a[i + 1] + 1) {
      a[i]--;
      k--;
    }
  for (int i = 1; i <= n; ++i) printf("%d ", a[i]);
}
