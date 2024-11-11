#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 10;
pair<int, int> l[MAXN], r[MAXN];
int ll[MAXN], rr[MAXN];
map<int, int> mapl;
map<int, int> mapr;
int main() {
  int n;
  scanf("%d", &n);
  int ansl = 0, ansr = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &ll[i], &rr[i]);
    l[i].first = ll[i];
    r[i].first = rr[i];
    l[i].second = i;
    r[i].second = i;
    if (mapl[ll[i]]) {
      int tmp = mapl[ll[i]];
      if (rr[tmp] > rr[i]) {
        ansl = i;
        ansr = tmp;
      } else {
        ansl = tmp;
        ansr = i;
      }
    }
    mapl[ll[i]] = i;
    if (mapr[rr[i]]) {
      int tmp = mapr[rr[i]];
      if (ll[tmp] > ll[i]) {
        ansl = tmp;
        ansr = i;
      } else {
        ansl = i;
        ansr = tmp;
      }
    }
    mapr[rr[i]] = i;
  }
  if (ansl) {
    printf("%d %d\n", ansl, ansr);
    return 0;
  }
  sort(l + 1, l + 1 + n);
  sort(r + 1, r + 1 + n);
  for (int i = 1; i <= n; i++) {
    if (l[i].second != r[i].second) {
      printf("%d %d\n", r[i].second, l[i].second);
      return 0;
    }
  }
  printf("-1 -1\n");
  return 0;
}
