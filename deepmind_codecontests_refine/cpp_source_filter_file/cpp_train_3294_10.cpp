#include <bits/stdc++.h>
using namespace std;
const int N = 2e2 + 5;
const int INF = 0x3f3f3f3f;
int a[N];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k, ans;
    scanf("%d%d", &n, &k);
    scanf("%d", &a[1]);
    ans = a[1];
    for (int i = (2); i <= (k); ++i) {
      scanf("%d", &a[i]);
      ans = max(ans, (a[i] - a[i - 1] + 1) / 2);
    }
    ans = max(ans, n - a[k] + 1);
    printf("%d\n", ans);
  }
  return 0;
}
