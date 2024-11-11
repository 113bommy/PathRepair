#include <bits/stdc++.h>
using namespace std;
struct data {
  long long cost, ind;
  bool st;
} ar[200000];
bool comp(data l, data r) {
  if (l.cost < r.cost) {
    return true;
  } else if (l.cost == r.cost) {
    if (l.st > r.st)
      return true;
    else
      return false;
  } else
    return false;
}
pair<long long, pair<long long, long long> > res[200000];
long long last[200000];
int main() {
  long long cs, t, i, j, k, x, y, z, ans, q, m, n, mn = LLONG_MAX, p;
  scanf("%lld", &n);
  scanf("%lld", &m);
  y = z = k = 0;
  for (i = 1; i <= m; i++) {
    scanf("%lld", &ar[i].cost);
    scanf("%lld", &ar[i].st);
    ar[i].ind = i;
  }
  sort(ar, ar + m + 1, comp);
  x = 2;
  y = 2;
  z = 3;
  for (i = 1; i <= n; i++) last[i] = i;
  for (i = 1; i <= m; i++) {
    if (ar[i].st == 1) {
      res[i] = pair<long long, pair<long long, long long> >(
          ar[i].ind, pair<long long, long long>(1, x));
      x++;
      y = 2;
      z = last[y] + 1;
    } else {
      if (z == x) {
        y++;
        z = last[y] + 1;
      }
      if (z >= x) {
        printf("-1\n");
        return 0;
      }
      res[i] = pair<long long, pair<long long, long long> >(
          ar[i].ind, pair<long long, long long>(y, z));
      last[y] = z;
      z++;
    }
  }
  sort(res + 1, res + m + 1);
  for (i = 1; i <= m; i++)
    printf("%lld %lld\n", res[i].second.first, res[i].second.second);
  return 0;
}
