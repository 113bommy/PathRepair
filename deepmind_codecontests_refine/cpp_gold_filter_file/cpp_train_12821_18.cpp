#include <bits/stdc++.h>
using namespace std;
int gi() {
  int x = 0, w = 1;
  char ch = getchar();
  while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
  if (ch == '-') w = 0, ch = getchar();
  while (ch >= '0' && ch <= '9')
    x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
  return w ? x : -x;
}
const int N = 1005;
int n, a[N], b[N], c[N], d[N], pa[N], pb[N], pc[N], pd[N];
vector<pair<pair<int, int>, pair<int, int> > > ans;
int main() {
  n = gi();
  for (int i = 1; i <= n; ++i) pb[b[i] = gi()] = i;
  for (int i = 1; i <= n; ++i) pa[a[i] = gi()] = i;
  for (int i = 1; i <= n; ++i) c[i] = d[i] = pc[i] = pd[i] = i;
  for (int i = 1; i <= n; ++i) {
    if (pa[i] == c[i] && pb[i] == d[i]) continue;
    ans.push_back(make_pair(make_pair(i, pc[pa[i]]), make_pair(pd[pb[i]], i)));
    int x = c[i], y = d[i];
    swap(c[i], c[pc[pa[i]]]);
    swap(pc[pa[i]], pc[x]);
    swap(d[i], d[pd[pb[i]]]);
    swap(pd[pb[i]], pd[y]);
  }
  printf("%d\n", ans.size());
  for (auto x : ans)
    printf("%d %d %d %d\n", x.first.first, x.first.second, x.second.first,
           x.second.second);
  return 0;
}
