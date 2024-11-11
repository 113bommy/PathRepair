#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 2;
const long long int inf = 2e9 + 2;
const long long int mod = 924844033;
const int lg = 20;
map<pair<long long int, long long int>, int> mp;
int par[N], num[N], n;
long long int x[N], y[N];
int find_par(int x) {
  if (par[x] == x) return x;
  return par[x] = find_par(par[x]);
}
inline bool check(long long int mid) {
  mp.clear();
  for (int i = 0; i < n; i++) {
    par[i] = i;
    num[i] = 0;
  }
  int t = n;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int u = find_par(i), v = find_par(j);
      if (u == v) continue;
      if ((x[i] == x[j] && abs(y[i] - y[j]) <= mid) ||
          (y[i] == y[j] && abs(x[i] - x[j]) <= mid)) {
        par[u] = v;
        t--;
      }
    }
  }
  if (t > 4) return 0;
  if (t == 1) return 1;
  if (t == 2) {
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (find_par(i) == find_par(j)) continue;
        if (((x[i] == x[j] && abs(y[i] - y[j]) <= 2 * mid) ||
             (y[i] == y[j] && abs(x[i] - x[j]) <= 2 * mid)))
          return 1;
      }
    }
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    int u = find_par(i);
    if (num[u] == 0) {
      num[u] = (1 << cnt);
      cnt++;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int u = find_par(i), v = find_par(j);
      if (u == v) continue;
      if (abs(x[i] - x[j]) <= mid && abs(y[i] - y[j]) <= mid) {
        pair<long long int, long long int> p1 = make_pair(x[i], y[j]);
        pair<long long int, long long int> p2 = make_pair(x[j], y[i]);
        mp[p1] |= (num[u] | num[v]);
        mp[p2] |= (num[u] | num[v]);
        if ((mp[p1] == (1 << cnt) - 1) || (mp[p2] == (1 << cnt) - 1)) return 1;
      }
    }
  }
  return 0;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%lld %lld", &x[i], &y[i]);
  if (!check(inf)) {
    printf("%lld", -1);
    return 0;
  }
  long long int l = 0, r = inf;
  while (l + 1 < r) {
    long long int mid = (l + r) / 2;
    if (check(mid))
      r = mid;
    else
      l = mid;
  }
  if (r == inf) r = -1;
  printf("%lld", r);
  return 0;
}
