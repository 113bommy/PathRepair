#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int T, n;
int a[N], cnt[N];
int main() {
  scanf("%d", &T);
  while (T--) {
    memset(cnt, 0, sizeof(cnt));
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]), cnt[a[i]]++;
    int ans = 0;
    int anscnt = 0;
    for (int i = 0; i <= n; i++) {
      if (cnt[i] == 0 && anscnt == 0)
        ans += i, anscnt = 2;
      else if (cnt[i] == 1 && anscnt == 0) {
        anscnt++;
        ans += i;
      } else if (cnt[i] == 0 && anscnt == 1) {
        anscnt++;
        ans += i;
      }
      if (anscnt == 2) break;
    }
    printf("%d\n", ans);
  }
}
