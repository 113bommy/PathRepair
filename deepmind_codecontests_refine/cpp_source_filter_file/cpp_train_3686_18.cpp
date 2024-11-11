#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> graf, par;
vector<int> deep, tav;
int n, m;
int mylog;
void dfs(int k, int p) {
  int q = p;
  if (p != -1) {
    par[k][0] = p;
    int i = 0;
    while (par[p][i] != -1) {
      par[k][i + 1] = par[p][i];
      p = par[p][i];
      i++;
    }
    deep[k] = deep[q] + 1;
  }
  for (int i : graf[k]) {
    if (i != q) dfs(i, k);
  }
}
int getpar(int k, int m) {
  if (m == 0 || k < 0) return k;
  int n = log2(m);
  return getpar(par[k][n], m - (1 << n));
}
int lca(int p, int q) {
  if (deep[p] != deep[q]) {
    int dif = abs(deep[p] - deep[q]);
    if (deep[p] > deep[q]) return lca(getpar(p, dif), q);
    return lca(p, getpar(q, dif));
  }
  if (p == q) return p;
  for (int i = log2(deep[p]) + 1; i >= 0; i--) {
    if (par[p][i] != par[q][i]) {
      p = par[p][i];
      q = par[q][i];
    }
    if (par[p][0] == par[q][0]) return par[p][0];
  }
}
int dist(int p, int q) { return deep[p] + deep[q] - 2 * deep[lca(p, q)]; }
void bfs(vector<int> raw) {
  vector<int> volt(n, 0);
  queue<int> sor;
  for (int i : raw) {
    tav[i] = 0;
    volt[i] = 1;
    sor.push(i);
  }
  while (!sor.empty()) {
    for (int i : graf[sor.front()]) {
      if (!volt[i]) {
        sor.push(i);
        tav[i] = tav[sor.front()] + 1;
        volt[i] = 1;
      }
    }
    sor.pop();
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  mylog = log2(n);
  graf.resize(n);
  tav.resize(n);
  par.resize(n, vector<int>(log2(n + 1) + 1, -1));
  deep.resize(n, 0);
  int in1, in2;
  for (int i = 0; i < n - 1; i++) {
    cin >> in1 >> in2;
    in1--;
    in2--;
    graf[in1].push_back(in2);
    graf[in2].push_back(in1);
  }
  dfs(0, -1);
  vector<int> piros(1, 0), temp(1, 0);
  bfs(piros);
  temp.clear();
  int szam = sqrt(n) / 2;
  for (int i = 0; i < min(50000, m); i++) {
    cin >> in1 >> in2;
    if (in1 == 1) {
      piros.push_back(in2 - 1);
      temp.push_back(in2 - 1);
    } else {
      int legk = tav[in2 - 1];
      for (int i : temp) {
        legk = min(legk, dist(in2 - 1, i));
      }
      cout << legk << '\n';
    }
    if (temp.size() > szam) {
      bfs(piros);
      temp.clear();
    }
  }
  return 0;
}
