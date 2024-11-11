#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
pair<int, int> a[N];
long long sum[N];
bool cmp(pair<int, int> a, pair<int, int> b) { return a.first > b.first; }
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
      int t, b;
      scanf("%d%d", &t, &b);
      a[i] = {t, b};
    }
    sort(a + 1, a + 1 + m, cmp);
    for (int i = 1; i <= m; i++) sum[i] = sum[i - 1] + a[i].first;
    long long ans = 0;
    for (int i = 1; i <= m; i++) {
      int l = 0, r = m;
      while (l < r) {
        int mid = l + r + 1 >> 1;
        if (a[mid].first >= a[i].second)
          l = mid;
        else
          r = mid - 1;
      }
      if (l >= n)
        ans = max(ans, sum[n]);
      else {
        l = min(l, m);
        if (l > i)
          ans = max(ans, sum[l] + 1ll * ((long long)n - l) * a[i].second);
        else
          ans = max(ans, sum[l] + a[i].first +
                             1ll * ((long long)n - l - 1) * a[i].second);
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}
