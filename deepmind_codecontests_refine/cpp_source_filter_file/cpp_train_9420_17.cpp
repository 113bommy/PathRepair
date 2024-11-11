#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000;
const int MAXL = 100000;
const int MAXP = 210;
int n, cnt[MAXL];
int pr[MAXP];
pair<int, int> leg[MAXN + 1];
int main(void) {
  scanf("%d", &n);
  memset(cnt, 0, sizeof cnt);
  memset(pr, 0, sizeof pr);
  for (int i = (0); i < (n); ++i) {
    scanf("%d", &leg[i].first);
  }
  int total = 0;
  for (int i = (0); i < (n); ++i) {
    scanf("%d", &leg[i].second);
    total += leg[i].second;
    leg[i].second *= -1;
  }
  sort(leg, leg + n);
  int ans = total;
  for (int i = 0; i < n;) {
    int j = i;
    while (j < n && leg[i].first == leg[j].first) {
      total += leg[j].second;
      cnt[leg[j].first]++;
      int uk = j + 1, k = cnt[leg[j].first];
      int x = max(uk - 2 * k + 1, 0);
      int p = 1, sum = 0;
      while (x > 0) {
        sum += min(x, pr[p]) * p;
        x -= min(x, pr[p]);
        ++p;
      }
      ans = min(ans, sum + total);
      ++j;
    }
    for (int k = i; k < j; ++k) ++pr[-leg[k].second];
    i = j;
  }
  printf("%d\n", ans);
  return 0;
}
