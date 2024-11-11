#include <bits/stdc++.h>
using namespace std;
using namespace std;
const int MAXN = 2e5 + 5;
const int MOD = 1e9 + 7;
int a[MAXN], n;
int main() {
  while (~scanf("%d", &n)) {
    int maxx = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      maxx = max(maxx, a[i]);
    }
    int num = 0, ans = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i] == maxx) {
        num++;
        ans = max(ans, num);
      } else {
        num = 0;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
