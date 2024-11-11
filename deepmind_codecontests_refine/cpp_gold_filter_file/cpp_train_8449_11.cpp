#include <bits/stdc++.h>
using namespace std;
const int MN = 222;
const int MM = 105;
long long res[MN][MN];
long long s, t, f, mf;
const long long INF = 1e12;
long long p[MN];
vector<int> g[MN];
void aug(int u, long long fl) {
  if (u == s) {
    f = fl;
    return;
  }
  aug(p[u], min(res[p[u]][u], fl));
  res[p[u]][u] -= f;
  res[u][p[u]] += f;
}
pair<long long, long long> st[MN], ed[MN];
set<long long> rv, cv;
map<long long, long long> rl, cl, rr, cr;
int main() {
  s = MN - 2;
  t = MN - 1;
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    a--;
    b--;
    st[i] = {a, b};
    ed[i] = {c, d};
    rv.insert(a);
    rv.insert(c);
    cv.insert(b);
    cv.insert(d);
  }
  int rid = 0;
  for (auto& it : rv) {
    rr[rid] = it;
    rl[it] = rid++;
  }
  rid = 0;
  for (auto& it : cv) {
    cr[rid] = it;
    cl[it] = rid++;
  }
  memset(res, 0, sizeof(res));
  for (int i = 0; i < m; i++) {
    int a = rl[st[i].first];
    int b = cl[st[i].second];
    int c = rl[ed[i].first];
    int d = cl[ed[i].second];
    for (int j = a; j < c; j++) {
      for (int k = b; k < d; k++) {
        if (res[j][k + MM] <= 0) {
          res[j][k + MM] = INF;
          g[j].push_back(k + MM);
          g[k + MM].push_back(j);
        }
      }
    }
  }
  long long rs = n;
  int id = rv.size() - 1;
  for (auto it = rv.rbegin(); it != rv.rend(); it++) {
    res[s][id] = rs - *it;
    g[s].push_back(id);
    g[id].push_back(s);
    rs = *it;
    id--;
  }
  rs = n;
  id = cv.size() - 1;
  for (auto it = cv.rbegin(); it != cv.rend(); it++) {
    res[id + MM][t] = rs - *it;
    g[t].push_back(id + MM);
    g[id + MM].push_back(t);
    rs = *it;
    id--;
  }
  while (1) {
    queue<int> q;
    bitset<MN> vs;
    q.push(s);
    vs.set(s);
    f = 0;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (res[u][v] <= 0) continue;
        if (vs[v]) continue;
        vs.set(v);
        q.push(v);
        p[v] = u;
      }
      if (vs[t]) break;
    }
    if (!vs[t]) break;
    aug(t, INF);
    if (f == 0) break;
    mf += f;
  }
  cout << mf << '\n';
}
