#include <bits/stdc++.h>
using namespace std;
const int maxn = 21000;
int n, m, t, ans[maxn], sum[maxn];
pair<int, int> a[maxn];
void init() {
  int first, second, z;
  for (int i = (1); i <= (n); ++i) {
    scanf("%d%*c%d%*c%d", &first, &second, &z);
    a[i] = make_pair(first * 3600 + second * 60 + z, i);
  }
  sort(a + 1, a + n + 1);
  memset(sum, 0, sizeof(sum));
}
void work() {
  int p = 1, ok = 0, first, num = 0, s = 0;
  for (int i = (1); i <= (n); ++i) {
    while (a[i].first - a[p].first > t) p++;
    if (i - p + 1 >= m) ok = 1;
  }
  if (!ok) {
    puts("No solution");
    return;
  }
  p = 1;
  for (int i = (1); i <= (n); ++i) {
    while (a[i].first - a[p].first >= t) {
      if (!(--sum[ans[a[p].second]])) s--;
      p++;
    }
    if (s < m)
      first = ++num;
    else
      first = ans[a[i - 1].second];
    ans[a[i].second] = first;
    if (!(sum[first]++)) s++;
  }
  printf("%d\n", num);
  for (int i = (1); i <= (n); ++i) printf("%d\n", ans[i]);
}
int main() {
  while (cin >> n >> m >> t) {
    init();
    work();
  }
  return 0;
}
