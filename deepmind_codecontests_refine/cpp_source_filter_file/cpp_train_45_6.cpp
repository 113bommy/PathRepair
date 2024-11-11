#include <bits/stdc++.h>
using namespace std;
int topstend[100000], topnode[100000], toppos, level[100000], dist[100000],
    parent[100000][20];
int n, topind[100000], q, a, b, c;
int distsum[100000], distsqsum[100000], nchildren[100000];
int pdistsum[100000][20], pdistsqsum[100000][20], pnchildren[100000][20];
vector<pair<int, int> > conn[100000];
int m(long long val) { return (val % 1000000007 + 1000000007) % 1000000007; }
int pathlen(int a, int b) { return m(dist[b] - dist[a]); }
void topdfs(int pos, int lev, int curdist, int curparent) {
  int curtoppos = toppos;
  level[pos] = lev;
  dist[pos] = curdist;
  parent[pos][0] = curparent;
  topnode[curtoppos] = pos;
  topind[pos] = curtoppos;
  toppos++;
  for (int i = 0; i < conn[pos].size(); i++)
    if (conn[pos][i].first != parent[pos][0])
      topdfs(conn[pos][i].first, lev + 1, m(curdist + conn[pos][i].second),
             pos);
  topstend[curtoppos] = toppos;
}
void calcdfs(int pos) {
  nchildren[pos] = 1;
  for (int i = 0; i < conn[pos].size(); i++)
    if (conn[pos][i].first != parent[pos][0]) {
      int child = conn[pos][i].first;
      calcdfs(child);
      nchildren[pos] += nchildren[child];
      distsum[pos] = m(distsum[pos] + distsum[child] +
                       1LL * nchildren[child] * conn[pos][i].second);
      distsqsum[pos] =
          m(distsqsum[pos] + distsqsum[child] +
            2LL * distsum[child] * conn[pos][i].second +
            1LL * m(1LL * conn[pos][i].second * conn[pos][i].second) *
                nchildren[child]);
      pnchildren[child][0] = m(-nchildren[child]);
      pdistsum[child][0] =
          m(-distsum[child] - 1LL * nchildren[child] * conn[pos][i].second);
      pdistsqsum[child][0] =
          m(-distsqsum[child] - 2LL * distsum[child] * conn[pos][i].second -
            1LL * m(1LL * conn[pos][i].second * conn[pos][i].second) *
                nchildren[child]);
    }
  for (int i = 0; i < conn[pos].size(); i++)
    if (conn[pos][i].first != parent[pos][0]) {
      int child = conn[pos][i].first;
      pnchildren[child][0] = m(pnchildren[child][0] + nchildren[pos]);
      pdistsum[child][0] = m(pdistsum[child][0] + distsum[pos]);
      pdistsqsum[child][0] = m(pdistsqsum[child][0] + distsqsum[pos]);
      pdistsqsum[child][0] =
          m(pdistsqsum[child][0] +
            2LL * conn[pos][i].second * pdistsum[child][0] +
            1LL * m(1LL * conn[pos][i].second * conn[pos][i].second) *
                pnchildren[child][0]);
      pdistsum[child][0] = m(pdistsum[child][0] +
                             1LL * pnchildren[child][0] * conn[pos][i].second);
    }
}
bool instree(int a, int b) {
  return topind[a] <= topind[b] && topind[b] < topstend[topind[a]];
}
int getanc(int a, int b) {
  if (instree(a, b)) return a;
  for (int i = 19; i >= 0; i--)
    if (parent[a][i] != -1 && !instree(parent[a][i], b)) a = parent[a][i];
  return parent[a][0];
}
int getdistsum;
int getsumto(int pos, int anc) {
  int ret = 0, rdistsum = 0, cdist = 0;
  for (int i = 19; i >= 0; i--)
    if (parent[pos][i] != -1 &&
        (parent[pos][i] == anc || !instree(parent[pos][i], anc))) {
      rdistsum =
          m(rdistsum + pdistsum[pos][i] + 1LL * pnchildren[pos][i] * cdist);
      ret = m(ret + pdistsqsum[pos][i] + 2LL * pdistsum[pos][i] * cdist +
              1LL * m(1LL * cdist * cdist) * pnchildren[pos][i]);
      cdist = m(cdist + pathlen(parent[pos][i], pos));
      pos = parent[pos][i];
    }
  getdistsum = rdistsum;
  return ret;
}
int main() {
  cin.sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    cin >> a >> b >> c;
    a--, b--;
    conn[a].push_back(make_pair(b, c));
    conn[b].push_back(make_pair(a, c));
  }
  topdfs(0, 0, 0, -1);
  calcdfs(0);
  for (int j = 1; j < 20; j++)
    for (int i = 0; i < n; i++) {
      if (parent[i][j - 1] != -1) {
        int par = parent[i][j - 1];
        parent[i][j] = parent[par][j - 1];
        pnchildren[i][j] = pnchildren[i][j - 1] + pnchildren[par][j - 1];
        pdistsum[i][j] = m(pdistsum[i][j - 1] + pdistsum[par][j - 1] +
                           1LL * pnchildren[par][j - 1] * pathlen(par, i));
        pdistsqsum[i][j] = m(pdistsqsum[i][j - 1] + pdistsqsum[par][j - 1] +
                             2LL * pdistsum[par][j - 1] * pathlen(par, i) +
                             1LL * m(1LL * pathlen(par, i) * pathlen(par, i)) *
                                 pnchildren[par][j - 1]);
      } else
        parent[i][j] = -1;
    }
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> a >> b, a--, b--;
    int res = 0;
    if (instree(b, a)) {
      res = distsqsum[a];
      res = m(res + getsumto(a, b));
      int bsqsum = getsumto(b, 0), cdist = pathlen(b, a);
      res = m(res - bsqsum - 2LL * getdistsum * cdist -
              m(1LL * cdist * cdist) * m(nchildren[0] - nchildren[b]));
    } else {
      res = m(-distsqsum[a] - getsumto(a, 0));
      int canc = getanc(a, b), cdist = m(pathlen(canc, a) + pathlen(canc, b));
      res = m(res + 2LL * m(distsqsum[b] + 2LL * cdist * distsum[b] +
                            1LL * m(1LL * cdist * cdist) * nchildren[b]));
    }
    cout << res << '\n';
  }
  return 0;
}
