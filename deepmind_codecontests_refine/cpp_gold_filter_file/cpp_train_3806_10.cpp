#include <bits/stdc++.h>
using namespace std;
const int MX = (1 << 17);
const long long inf = (1ll << 61);
vector<pair<int, int> > v[MX];
vector<int> par[MX];
priority_queue<pair<long long, int> > Q;
int n;
long long dijsktra(int src, int snk, long long *dis) {
  for (int j = 1; j <= n; j++) {
    dis[j] = inf;
    par[j].clear();
  }
  dis[src] = 0;
  Q.push({0, src});
  while (!Q.empty()) {
    long long cost = -Q.top().first, x = Q.top().second;
    Q.pop();
    long long nxt, ncost;
    for (auto pp : v[x]) {
      nxt = pp.first, ncost = cost + pp.second;
      if (dis[nxt] > ncost) {
        dis[nxt] = ncost;
        par[nxt].clear();
        Q.push({-ncost, nxt});
      }
      if (dis[nxt] == ncost) par[nxt].push_back(x);
    }
  }
  return dis[snk];
}
int is[1005][1005];
int SP, src, snk, m, ans[MX], Theta;
bool nosol = 0;
bool done[MX];
void go(int x) {
  if (x == src) nosol = 1;
  if (done[x]) return;
  done[x] = 1;
  for (auto p : par[x]) {
    if (is[p][x])
      ans[is[p][x]] += Theta;
    else
      go(p);
  }
}
int A[MX], B[MX], C[MX];
long long disrc[MX], disnk[MX];
bool check(int mid) {
  for (int j = 1; j <= n; j++) v[j].clear();
  for (int j = 1; j <= m; j++) {
    int cc = C[j];
    if (cc == 0) {
      if (j > mid) continue;
      cc = 1;
    }
    v[A[j]].push_back({B[j], cc});
    v[B[j]].push_back({A[j], cc});
  }
  long long aa = dijsktra(src, snk, disrc);
  return aa > SP;
}
int main() {
  scanf("%d %d %d %d %d", &n, &m, &SP, &src, &snk);
  ++src;
  ++snk;
  int tt = 0;
  for (int j = 1; j <= m; j++) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    a++;
    b++;
    A[j] = a, B[j] = b, C[j] = c;
    ans[j] = c;
    if (c) {
      v[a].push_back(make_pair(b, c));
      v[b].push_back(make_pair(a, c));
    }
  }
  long long omar = dijsktra(src, snk, disrc);
  if (dijsktra(src, snk, disrc) < SP) {
    puts("NO");
    return 0;
  }
  if (omar == SP) {
    for (int j = 1; j <= m; j++)
      if (C[j] == 0)
        ans[j] = (1 << 30);
      else
        ans[j] = C[j];
    puts("YES");
    for (int j = 1; j <= m; j++)
      printf("%d %d %d\n", A[j] - 1, B[j] - 1, ans[j]);
    return 0;
  }
  int st = 0, en = m, mid, best;
  while (st <= en) {
    mid = (st + en) / 2;
    if (check(mid)) {
      best = mid;
      st = mid + 1;
    } else
      en = mid - 1;
  }
  if (best == m) {
    puts("NO");
    return 0;
  }
  check(best);
  for (int j = 1; j <= best; j++)
    if (C[j] == 0) ans[j] = 1;
  for (int j = best + 2; j <= m; j++)
    if (C[j] == 0) ans[j] = (1 << 30);
  ++best;
  dijsktra(src, snk, disrc);
  dijsktra(snk, src, disnk);
  int uu = A[best], vv = B[best];
  if (disrc[uu] + disnk[vv] > disrc[vv] + disnk[uu]) swap(uu, vv);
  ans[best] = SP - disrc[uu] - disnk[vv];
  puts("YES");
  for (int j = 1; j <= m; j++) {
    printf("%d %d %d\n", A[j] - 1, B[j] - 1, ans[j]);
  }
}
