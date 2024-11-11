#include <bits/stdc++.h>
using namespace std;
int const N = 1010;
int a[N];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= (n * 2); ++i) scanf("%d", &a[i]);
  int ans = 0;
  for (int i = 1; i < n * 2; i += 2) {
    if (a[i] == a[i + 1]) continue;
    for (int j = i + 1; j <= n * 2; ++j) {
      if (a[j] == a[i]) {
        for (int k = j - 1; k > i; --k) {
          swap(a[k], a[k + 1]);
          ++ans;
        }
        break;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
