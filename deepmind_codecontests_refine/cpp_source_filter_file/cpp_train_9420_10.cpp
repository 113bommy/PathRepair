#include <bits/stdc++.h>
using namespace std;
const int N = 100005, INF = ~0u >> 1;
pair<int, int> a[N];
int d[N], b[N];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i].first);
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i].second);
    sum += a[i].second;
  }
  sort(a, a + n);
  int ans = INF;
  for (int i = 1, j = 0; i <= 100000; ++i) {
    int cnt = 0;
    while (a[j].first <= i && j < n) {
      if (a[j].first == i)
        b[++cnt] = a[j].second;
      else
        ++d[a[j].second];
      sum -= a[j].second;
      ++j;
    }
    if (cnt * 2 > j)
      ans = min(ans, sum);
    else {
      int tmp = j - cnt * 2 + 1;
      int tsum = 0, tret = 0;
      for (int k = 1; k <= 200; ++k) {
        tsum += d[k];
        tret += d[k] * k;
        if (tsum >= tmp) {
          tret -= (tsum - tmp) * k;
          ans = min(ans, sum + tret);
          break;
        }
      }
    }
    for (int k = 0; k < cnt; ++k) ++d[b[k]];
  }
  printf("%d\n", ans);
  return 0;
}
