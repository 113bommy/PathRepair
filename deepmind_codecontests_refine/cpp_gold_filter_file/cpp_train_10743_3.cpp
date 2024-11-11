#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1010;
int n, m, a[MAXN];
int main() {
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int ans = 0;
    cin >> n >> m;
    for (register int i = 1; i <= n; ++i) cin >> a[i];
    if (n > m || n == 2) {
      puts("-1");
      continue;
    }
    for (register int i = 1; i <= n; ++i) ans += a[i] + a[i];
    m -= n;
    int minn1 = 0x3f3f3f3f, minn2 = 0x3f3f3f3f, p1, p2;
    for (register int i = 1; i <= n; ++i) {
      if (a[i] < minn1)
        p2 = p1, p1 = i, minn2 = minn1, minn1 = a[i];
      else if (a[i] < minn2)
        minn2 = a[i], p2 = i;
    }
    ans += m * (minn1 + minn2);
    printf("%d\n", ans);
    for (register int i = 1; i <= m; ++i) printf("%d %d\n", p1, p2);
    for (register int i = 2; i <= n; ++i) printf("%d %d\n", i, i - 1);
    printf("1 %d\n", n);
  }
  return 0;
}
