#include <bits/stdc++.h>
using namespace std;
template <class T>
T sqr(T x) {
  return x * x;
}
const int maxn = 2000000;
int a[maxn], b[maxn];
int n;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
  int j = 0;
  long long sa = 0;
  long long sb = 0;
  map<long long, pair<int, int> > hashs;
  hashs[0] = pair<int, int>(0, 0);
  int flag = 0;
  for (int i = 1; i <= n; i++) {
    sa += a[i];
    while (j < n && sb + b[j + 1] <= sa) sb += b[++j];
    if (hashs.find(sa - sb) != hashs.end()) {
      int l1 = hashs[sa - sb].first;
      int l2 = hashs[sa - sb].second;
      printf("%d\n", i - l1);
      for (int ii = l1 + 1; ii <= i; ii++)
        printf("%d%c", ii, (ii == i) ? '\n' : ' ');
      printf("%d\n", j - l2);
      for (int ii = l2 + 1; ii <= j; ii++)
        printf("%d%c", ii, (ii == j) ? '\n' : ' ');
      flag = 1;
      return 0;
    }
    hashs[sa - sb] = pair<int, int>(i, j);
  }
  if (!flag) puts("-1");
  return 0;
}
