#include <bits/stdc++.h>
using namespace std;
template <class T>
T sqr(T x) {
  return x * x;
}
const int maxn = 200001;
pair<pair<int, int>, int> a[maxn];
pair<pair<int, int>, pair<int, int> > b[maxn];
int n, m;
int ans[maxn], x, y, z;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &x, &y);
    a[i] = pair<pair<int, int>, int>(pair<int, int>(x, y), i);
  }
  sort(a + 1, a + 1 + n);
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%d", &x, &y, &z);
    b[i] = pair<pair<int, int>, pair<int, int> >(pair<int, int>(x, y),
                                                 pair<int, int>(z, i));
  }
  sort(b + 1, b + 1 + m);
  int tag = 0;
  multimap<int, pair<int, int> > tree;
  for (int i = 1; i <= n; i++) {
    while (tag < m && a[i].first.first >= b[tag + 1].first.first) {
      tag++;
      tree.insert(pair<int, pair<int, int> >(
          b[tag].first.second,
          pair<int, int>(b[tag].second.first, b[tag].second.second)));
    }
    if (!tag) {
      puts("NO");
      return 0;
    }
    auto xx = tree.lower_bound(a[i].first.second);
    if (xx == tree.end()) {
      puts("NO");
      return 0;
    }
    ans[a[i].second] = xx->second.second;
    xx->second.first--;
    if (xx->second.first == 0) tree.erase(xx);
  }
  puts("YES");
  for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
  fclose(stdin);
  return 0;
}
