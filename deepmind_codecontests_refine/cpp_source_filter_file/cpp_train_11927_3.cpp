#include <bits/stdc++.h>
using namespace std;
const long long N = 2e3 + 5;
long long ID[N][N], IND[N][N], n, m, k, q, l, r, x, y, xx, yy, w, ST[N];
long long rt;
char s[N];
struct fen {
  long long D[N];
  inline fen() { memset(D, 0, sizeof(D)); }
  void add(long long ind, long long d) {
    for (ind++; ind < N; ind += ind & -ind) D[ind] += d;
  }
  long long get(long long ind) {
    long long sm = 0;
    for (ind++; ind; ind -= ind & -ind) sm += D[ind];
    return (sm);
  }
  long long get(long long l, long long r) { return (get(r + 1) - get(l)); }
};
struct gar {
  fen f;
  long long x, y, ln;
  long long sm = 0;
} G[N];
int32_t main() {
  fill(ST, ST + N, 1);
  scanf("%d %d %d", &n, &m, &k);
  for (long long i = 1; i <= k; i++) {
    scanf("%lld", &G[i].ln);
    for (long long j = 0; j < G[i].ln; j++) {
      scanf("%lld %ld %lld", &x, &y, &w);
      G[i].sm += w;
      ID[x][y] = i, IND[x][y] = j;
      G[i].f.add(j, w);
    }
    G[i].x = x, G[i].y = y;
  }
  scanf("%lld", &q);
  for (long long Q = 0; Q < q; Q++) {
    scanf("%s", s);
    if (s[0] == 'S') {
      scanf("%lld", &x), ST[x] ^= 1;
      continue;
    }
    scanf("%lld %lld %lld %lld", &x, &y, &xx, &yy);
    vector<pair<long long, bool> > v[N];
    for (long long i = x; i <= xx; i++) {
      if (ID[i][y] && ID[i][y] == ID[i][y - 1]) {
        if (IND[i][y] + 1 == IND[i][y - 1])
          v[ID[i][y]].push_back({IND[i][y], 1});
        else if (IND[i][y] - 1 == IND[i][y - 1])
          v[ID[i][y]].push_back({IND[i][y], 0});
      }
      if (ID[i][yy] && ID[i][yy] == ID[i][yy + 1]) {
        if (IND[i][yy] + 1 == IND[i][yy + 1])
          v[ID[i][yy]].push_back({IND[i][yy], 1});
        else if (IND[i][yy] - 1 == IND[i][yy + 1])
          v[ID[i][yy]].push_back({IND[i][yy], 0});
      }
    }
    for (long long i = y; i <= yy; i++) {
      if (ID[x][i] && ID[x][i] == ID[x - 1][i]) {
        if (IND[x][i] + 1 == IND[x - 1][i])
          v[ID[x][i]].push_back({IND[x][i], 1});
        else if (IND[x][i] - 1 == IND[x - 1][i])
          v[ID[x][i]].push_back({IND[x][i], 0});
      }
      if (ID[xx][i] && ID[xx][i] == ID[xx + 1][i]) {
        if (IND[xx][i] + 1 == IND[xx + 1][i])
          v[ID[xx][i]].push_back({IND[xx][i], 1});
        else if (IND[xx][i] - 1 == IND[xx + 1][i])
          v[ID[xx][i]].push_back({IND[xx][i], 0});
      }
    }
    rt = 0;
    for (long long i = 1; i <= k; i++)
      if (ST[i]) {
        sort(v[i].begin(), v[i].end());
        if (v[i].empty()) {
          if (G[i].x >= x && G[i].x <= xx && G[i].y >= y && G[i].y <= yy)
            rt += G[i].sm;
          continue;
        }
        if (v[i][0].second) rt += G[i].f.get(0, v[i][0].first);
        if (v[i].back().second == 0) v[i].push_back({G[i].ln - 1, 1});
        for (long long j = (long long)v[i].size() & 1;
             j < (long long)v[i].size(); j += 2) {
          rt += G[i].f.get(v[i][j].first, v[i][j + 1].first);
        }
      }
    printf("%lld\n", rt);
  }
}
