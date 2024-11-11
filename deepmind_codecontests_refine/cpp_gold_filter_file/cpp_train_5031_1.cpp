#include <bits/stdc++.h>
using namespace std;
long long magic = 37;
long long p[1100000];
long long a[1100000];
vector<pair<int, int> > bian;
vector<long long> aa;
int main() {
  long long i, j, ans, cnt, b1;
  int m, n, x, y;
  scanf("%d%d", &n, &m);
  p[0] = magic;
  for (i = 1; i < n; i++) p[i] = p[i - 1] * magic;
  for (i = 0; i < n; i++) {
    a[i] = 0;
  }
  bian.clear();
  for (i = 0; i < m; i++) {
    scanf("%d%d", &x, &y);
    x--;
    y--;
    a[x] += p[y];
    a[y] += p[x];
    bian.push_back(make_pair(x, y));
  }
  ans = 0;
  aa.clear();
  for (i = 0; i < n; i++) aa.push_back(a[i]);
  sort(aa.begin(), aa.end());
  cnt = 1;
  for (i = 1; i < n; i++)
    if (aa[i] != aa[i - 1]) {
      ans += cnt * (cnt - 1) / 2;
      cnt = 1;
    } else
      cnt++;
  ans += cnt * (cnt - 1) / 2;
  for (i = 0; i < bian.size(); i++)
    if (a[bian[i].first] + p[bian[i].first] ==
        a[bian[i].second] + p[bian[i].second])
      ans++;
  printf("%I64d\n", ans);
}
