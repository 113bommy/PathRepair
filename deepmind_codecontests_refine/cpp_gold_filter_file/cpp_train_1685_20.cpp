#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 7;
int t, n, a[N];
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int cot = 0, mi = a[n];
    for (int i = n - 1; i >= 1; i--) {
      if (a[i] <= mi) {
        mi = a[i];
      } else {
        cot++;
      }
    }
    printf("%d\n", cot);
  }
  return 0;
}
