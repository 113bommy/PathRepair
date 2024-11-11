#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10, MOD = 1e9 + 7;
long long diss[MAXN], dist[MAXN], cntws[MAXN], cntwt[MAXN];
vector<pair<int, int> > Mat[MAXN], Matr[MAXN];
vector<pair<pair<int, int>, int> > edg;
set<pair<long long, int> > S;
int n, m, s, t;
bool se[MAXN];
bool cmp(int a, int b) { return diss[a] < diss[b]; }
void addv(int v) {
  for (int i = 0; i < Mat[v].size(); i++)
    if (!se[Mat[v][i].first])
      S.insert({diss[v] + Mat[v][i].second, Mat[v][i].first});
}
void updv(int v) {
  for (int i = 0; i < Matr[v].size(); i++)
    if (diss[Matr[v][i].first] + Matr[v][i].second == diss[v]) {
      cntws[v] += cntws[Matr[v][i].first];
      cntws[v] %= MOD;
    }
}
void Dij(int v) {
  S.clear();
  for (int i = 0; i <= n; i++) se[i] = 0, diss[i] = 1e16, cntws[i] = 0;
  S.insert({0, v});
  while (!S.empty()) {
    int v = (*S.begin()).second;
    long long d = (*S.begin()).first;
    S.erase(S.begin());
    if (se[v]) continue;
    se[v] = 1;
    diss[v] = d;
    addv(v);
  }
  cntws[v] = 1;
  vector<int> vc;
  for (int i = 1; i <= n; i++) vc.push_back(i);
  sort(vc.begin(), vc.end(), cmp);
  for (int i = 1; i < vc.size(); i++) updv(vc[i]);
}
int main() {
  cin >> n >> m >> s >> t;
  for (int i = 0; i < m; i++) {
    int a, b, w;
    cin >> a >> b >> w;
    Mat[a].push_back({b, w});
    Matr[b].push_back({a, w});
    edg.push_back({{a, b}, w});
  }
  Dij(s);
  swap(diss, dist);
  swap(Mat, Matr);
  swap(cntws, cntwt);
  Dij(t);
  swap(diss, dist);
  swap(Mat, Matr);
  swap(cntws, cntwt);
  long long cur = diss[t], CNT = cntws[t];
  for (int i = 0; i < edg.size(); i++) {
    int a = edg[i].first.first, b = edg[i].first.second;
    long long w = edg[i].second;
    if (CNT == 0) {
      cout << "NO" << endl;
      continue;
    }
    if ((cntws[a] * cntwt[b]) % MOD == CNT && diss[a] + dist[b] + w == cur)
      cout << "YES" << endl;
    else if (diss[a] + dist[b] + 1 < cur)
      cout << "CAN " << w - (cur - 1 - (diss[a] + dist[b])) << endl;
    else
      cout << "NO" << endl;
  }
}
