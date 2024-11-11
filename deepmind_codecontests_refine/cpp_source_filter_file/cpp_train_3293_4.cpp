#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 15;
int a[N], L[N], R[N];
bool is[N];
int pl[N], pr[N];
int sz[N];
int find(int *par, int ind) {
  if (is[ind]) return ind;
  return par[ind] = find(par, par[ind]);
}
int main() {
  int n, i;
  cin >> n;
  for (i = 1; i <= n; ++i) scanf("%d", &a[i]);
  int j;
  priority_queue<pair<int, pair<int, int> > > pq;
  for (i = 1; i <= n;) {
    for (j = i; j <= n; ++j) {
      if (a[j] != a[i]) break;
    }
    is[i] = 1;
    is[j - 1] = 1;
    R[i] = j - 1;
    L[j - 1] = i;
    L[i] = i - 1;
    R[j - 1] = j;
    pr[i] = j - 1;
    pl[j - 1] = i;
    sz[i] = j - i;
    sz[j - 1] = j - i;
    pq.push(make_pair(j - i, make_pair(i, j - 1)));
    i = j;
  }
  is[n + 1] = 1;
  is[0] = 1;
  int ret = 0, u, v;
  while (!pq.empty()) {
    int l = pq.top().second.first, r = pq.top().second.second;
    pq.pop();
    if (pr[l] == r && pl[r] == l) {
      ++ret;
    } else
      continue;
    is[l] = is[r] = 0;
    u = find(L, l);
    v = find(R, r);
    if (u == 0 || v == n + 1) continue;
    if (a[u] == a[v]) {
      is[u] = is[v] = 0;
      int x = pl[u], y = pr[v];
      int nsz = sz[x] + sz[y];
      R[u] = y;
      L[u] = x;
      L[v] = x;
      R[v] = y;
      L[x] = x - 1;
      R[y] = y + 1;
      is[x] = is[y] = 1;
      sz[x] = sz[y] = nsz;
      pr[x] = y;
      pl[y] = x;
      pq.push(make_pair(nsz, make_pair(x, y)));
    } else
      continue;
  }
  cout << ret << endl;
}
