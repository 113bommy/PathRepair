#include <bits/stdc++.h>
using namespace std;
const int N = 123456;
int m, n;
struct stage {
  int t, x, c;
  long long size;
} st[N];
int main() {
  scanf("%d", &m);
  for (int i = 0; i < m; ++i) {
    scanf("%d %d", &st[i].t, &st[i].x);
    if (st[i].t == 2) scanf("%d", &st[i].c);
    if (i == 0)
      st[i].size = 1;
    else
      st[i].size = st[i - 1].size + (st[i].t == 1 ? 1 : st[i].x * st[i].c);
  }
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    long long id;
    scanf("%I64d", &id);
    --id;
    int ll, rr;
    long long size = 0, x = id + 1;
    do {
      id -= size;
      id %= x;
      ll = 0, rr = m - 1;
      while (ll < rr) {
        int mid = (ll + rr) >> 1;
        if (st[mid].size <= id)
          ll = mid + 1;
        else
          rr = mid;
      }
      size = st[ll - 1].size;
      x = st[ll].x;
    } while (st[ll].t != 1);
    printf("%d%c", st[ll].x, " \n"[i == n - 1]);
  }
  return 0;
}
