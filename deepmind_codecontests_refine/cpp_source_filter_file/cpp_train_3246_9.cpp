#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e5 + 5;
const int MOD = 1e9 + 7;
int a[maxn];
int cnt[maxn];
int main() {
  int n = 0, k = 0;
  while (~scanf("%d %d", &n, &k)) {
    for (int i = 1; i <= n; i++) {
      scanf("%d", a + i);
      cnt[a[i]]++;
    }
    int ans = 0;
    int odd = 0;
    for (int i = 1; i <= n; i++) {
      if (cnt[i] % 2 == 1) {
        odd++;
        ans += cnt[i] - 1;
      } else {
        ans += cnt[i];
      }
    }
    printf("%d\n", ans + (odd + 1) / 2);
  }
  return 0;
}
