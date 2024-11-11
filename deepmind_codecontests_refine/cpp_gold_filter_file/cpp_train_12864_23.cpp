#include <bits/stdc++.h>
using namespace std;
const size_t N = 200005;
int n;
long long t[N];
long long p[N];
long long d[N];
int par[N];
long long ans[N];
int getId(long long tripTime, int i) {
  int res = (int)(upper_bound(p, p + n + 1, p[i] - tripTime) - p);
  if (res != 0) --res;
  return res;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &p[i]);
  }
  for (int i = 1; i <= n; ++i) {
    d[i] = d[i - 1] + 20;
    par[i] = i - 1;
    int id = getId(90, i);
    if (id != i && d[i] > d[id] + 50) {
      d[i] = d[id] + 50;
      par[i] = id;
    }
    id = getId(1440, i);
    if (id != i && d[i] > d[id] + 120) {
      d[i] = d[id] + 120;
      par[i] = id;
    }
  }
  for (int i = 1; i <= n; ++i) ans[i] = d[i] - d[i - 1];
  for (int i = 1; i <= n; ++i) printf("%lld\n", ans[i]);
  return 0;
}
