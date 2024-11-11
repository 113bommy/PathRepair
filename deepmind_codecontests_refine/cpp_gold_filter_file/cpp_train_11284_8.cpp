#include <bits/stdc++.h>
using namespace std;
const int MAX = 200100;
int a[MAX];
int main() {
  int n, k, a, prev = 0, j = 1;
  long long ans;
  scanf("%d%d", &n, &k);
  for (int i = 1; i < n; i++) {
    scanf("%d", &a);
    if (i > 1) {
      ans = prev - (1LL * (n - i) * a * j);
      if (ans < k)
        printf("%d\n", i);
      else {
        prev += 1LL * a * j;
        ++j;
      }
    }
  }
  return 0;
}
