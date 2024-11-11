#include <bits/stdc++.h>
const double Pi = acos(-1.0);
using namespace std;
const int maxN = 100010;
long long n;
long long a[maxN];
vector<int> G[maxN];
long long dist[maxN], mxpath[maxN];
void dfsInit(int cur, int pre) {
  dist[cur] = a[cur];
  long long mx1 = 0, mx2 = 0;
  for (int i = 0; i < (int)G[cur].size(); i++) {
    int nxt = G[cur][i];
    if (nxt == pre) continue;
    dfsInit(nxt, cur);
    dist[cur] = max(dist[nxt] + a[cur], dist[cur]);
    if (dist[nxt] > mx1) {
      mx2 = mx1;
      mx1 = dist[nxt];
    } else if (dist[nxt] > mx2)
      mx2 = dist[nxt];
    mxpath[cur] = max(mxpath[nxt], mxpath[cur]);
  }
  mxpath[cur] = max(mxpath[cur], mx1 + mx2 + a[cur]);
}
long long ans;
void dfsSolve(int cur, int pre, long long best, long long mxdist) {
  ans = max(ans, best + mxpath[cur]);
  set<pair<long long, long long> > sPath, sDist;
  sPath.insert(pair<long long, long long>(-best, -1));
  sDist.insert(pair<long long, long long>(-mxdist, -1));
  for (int i = 0; i < (int)G[cur].size(); i++) {
    int nxt = G[cur][i];
    if (nxt == pre) continue;
    sPath.insert(pair<long long, long long>(-mxpath[nxt], i));
    sDist.insert(pair<long long, long long>(-dist[nxt], i));
  }
  for (int i = 0; i < (int)G[cur].size(); i++) {
    int nxt = G[cur][i];
    if (nxt == pre) continue;
    sPath.erase(pair<long long, long long>(-mxpath[nxt], i));
    sDist.erase(pair<long long, long long>(-dist[nxt], i));
    long long bP = -(*sPath.begin()).first, cP = a[cur];
    int cnt = 0;
    for (set<pair<long long, long long> >::iterator it = sDist.begin();
         it != sDist.end() && cnt < 2; cnt++, it++)
      cP += -(*it).first;
    dfsSolve(nxt, cur, max(bP, cP), -(*sDist.begin()).first + a[cur]);
    sPath.insert(pair<long long, long long>(-mxpath[nxt], i));
    sDist.insert(pair<long long, long long>(-dist[nxt], i));
  }
}
int main(int argc, char** argv) {
  scanf("%I64d", &n);
  for (int i = 0; i < n; i++) scanf("%I64d", &a[i]);
  int u, v;
  for (int i = 0; i < n - 1; i++) {
    scanf("%d %d", &u, &v);
    u--;
    v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  dfsInit(0, -1);
  dfsSolve(0, -1, 0, 0);
  printf("%I64d\n", ans);
  return 0;
}
