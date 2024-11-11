#include <bits/stdc++.h>
using namespace std;
const int N = 1000 * 100 + 10;
const int M = 19;
const long long INF = 1000LL * 1000LL * 1000LL * 1000LL * 5LL;
const int rozmiar = 1 << 18;
vector<long long> Girls[N];
vector<int> Graf[N];
vector<pair<int, int> > Sciezka[N];
int Parent[M][N];
pair<int, int> Order[N];
pair<int, int> Poz[N];
int Syn[N];
int Nr[N], Ost[N];
pair<int, int> Pre[N];
int Rozmiar[N];
vector<pair<pair<long long, long long>, int> > DP[N];
long long FT[2 * rozmiar];
vector<pair<long long, long long> > Prz[N];
int t;
void Przepchnij(int i, int v) {
  DP[i][2 * v].first.first += Prz[i][v].first;
  DP[i][2 * v].first.second += Prz[i][v].second;
  DP[i][2 * v + 1].first.first += Prz[i][v].first;
  DP[i][2 * v + 1].first.second += Prz[i][v].second;
  Prz[i][2 * v].first += Prz[i][v].first;
  Prz[i][2 * v].second += Prz[i][v].second;
  Prz[i][2 * v + 1].first += Prz[i][v].first;
  Prz[i][2 * v + 1].second += Prz[i][v].second;
  Prz[i][v] = make_pair(0, 0);
}
void Dodaj(int i, int v, int p_b, int k_b, int p, int k,
           pair<long long, long long> w) {
  if (p_b > k || k_b < p) return;
  if (p <= p_b && k_b <= k) {
    DP[i][v].first.first += w.first;
    DP[i][v].first.second += w.second;
    Prz[i][v].first += w.first;
    Prz[i][v].second += w.second;
    return;
  }
  Przepchnij(i, v);
  Dodaj(i, 2 * v, p_b, (p_b + k_b) / 2, p, k, w);
  Dodaj(i, 2 * v + 1, (p_b + k_b) / 2 + 1, k_b, p, k, w);
  DP[i][v] = min(DP[i][2 * v], DP[i][2 * v + 1]);
}
pair<pair<long long, long long>, int> WezMin(int i, int v, int p_b, int k_b,
                                             int p, int k) {
  if (p_b > k || k_b < p) return make_pair(make_pair(INF, INF), 0);
  if (p <= p_b && k_b <= k) {
    return DP[i][v];
  }
  Przepchnij(i, v);
  return min(WezMin(i, 2 * v, p_b, (p_b + k_b) / 2, p, k),
             WezMin(i, 2 * v + 1, (p_b + k_b) / 2 + 1, k_b, p, k));
  DP[i][v] = min(DP[i][2 * v], DP[i][2 * v + 1]);
}
void DodajFT(int p, int k, long long w) {
  FT[p] += w;
  if (p != k) FT[k] += w;
  while (p / 2 != k / 2) {
    if (p % 2 == 0) FT[p + 1] += w;
    if (k % 2 == 1) FT[k - 1] += w;
    p /= 2;
    k /= 2;
  }
}
long long SumaFT(int v) {
  long long res = FT[v];
  v /= 2;
  while (v > 0) {
    res += FT[v];
    v /= 2;
  }
  return res;
}
bool Przodek(int v, int u) {
  if (Order[v].first <= Order[u].first && Order[u].second <= Order[v].second)
    return true;
  return false;
}
int LCA(int v, int u) {
  int m;
  if (Przodek(v, u)) return v;
  if (Przodek(u, v)) return u;
  m = M - 1;
  while (m > 0) {
    while (m > 0 && Przodek(Parent[m][v], u)) m--;
    if (!Przodek(Parent[m][v], u)) v = Parent[m][v];
  }
  if (Przodek(v, u)) return v;
  return Parent[0][v];
}
void Wczytaj(int n, int m) {
  int i, a, v, u;
  for (i = 0; i < n - 1; i++) {
    scanf("%d%d", &v, &u);
    Graf[v].push_back(u);
    Graf[u].push_back(v);
  }
  for (i = 1; i <= m; i++) {
    scanf("%d", &a);
    Girls[a].push_back(i);
  }
}
void DFSLCA(int v, int ojciec) {
  int i;
  Parent[0][v] = ojciec;
  Order[v].first = t++;
  for (i = 0; i < Graf[v].size(); i++) {
    if (Graf[v][i] != ojciec) DFSLCA(Graf[v][i], v);
  }
  Order[v].second = t++;
}
void DFSHLD(int v, int ojciec) {
  int i;
  Syn[v] = 1;
  for (i = 0; i < Graf[v].size(); i++) {
    if (Graf[v][i] != ojciec) {
      DFSHLD(Graf[v][i], v);
      Syn[v] += Syn[Graf[v][i]];
    }
  }
  Nr[v] = v;
  for (i = 0; i < Graf[v].size(); i++) {
    if (Graf[v][i] != ojciec && 2 * Syn[Graf[v][i]] > Syn[v])
      Nr[v] = Nr[Graf[v][i]];
  }
  Poz[v] = make_pair(Sciezka[Nr[v]].size(),
                     Sciezka[Nr[v]].size() + Girls[v].size() - 1);
  Ost[Nr[v]] = v;
  for (i = 0; i < Girls[v].size(); i++) {
    Sciezka[Nr[v]].push_back(make_pair(Girls[v][i], v));
  }
}
void MakeTrees(int n) {
  int i, j;
  for (i = 1; i <= n; i++) {
    Rozmiar[i] = 1;
    while (Rozmiar[i] <= Sciezka[i].size()) Rozmiar[i] *= 2;
    for (j = 0; j < 2 * Rozmiar[i]; j++) {
      DP[i].push_back(make_pair(make_pair(0, 0), j - Rozmiar[i]));
      Prz[i].push_back(make_pair(0, 0));
    }
    for (j = 0; j < Sciezka[i].size(); j++)
      Dodaj(i, 1, 0, Rozmiar[i] - 1, j, j, Sciezka[i][j]);
    for (; j < Rozmiar[i]; j++)
      Dodaj(i, 1, 0, Rozmiar[i] - 1, j, j, make_pair(INF, INF));
  }
}
void DFSList(int v, int parent) {
  int i;
  Pre[v].second = Pre[v].first = t++;
  for (i = 0; i < Graf[v].size(); i++) {
    if (Graf[v][i] != parent) {
      DFSList(Graf[v][i], v);
      Pre[v].second = max(Pre[v].second, Pre[Graf[v][i]].second);
    }
  }
}
void Inicjuj(int n) {
  int i, j;
  DFSLCA(1, 1);
  for (j = 1; j < M; j++) {
    for (i = 1; i <= n; i++) Parent[j][i] = Parent[j - 1][Parent[j - 1][i]];
  }
  DFSHLD(1, 1);
  MakeTrees(n);
  t = 0;
  DFSList(1, 1);
}
pair<pair<long long, long long>, pair<int, int> > BestGirl(int v, int u) {
  pair<pair<long long, long long>, pair<int, int> > res, a_best_g;
  pair<pair<long long, long long>, int> best_g;
  int x;
  res = make_pair(make_pair(INF, INF), make_pair(0, 0));
  while (!Przodek(Ost[Nr[v]], u)) {
    x = Ost[Nr[v]];
    if (Poz[v].first <= Poz[x].second) {
      best_g =
          WezMin(Nr[v], 1, 0, Rozmiar[Nr[v]] - 1, Poz[v].first, Poz[x].second);
      a_best_g = make_pair(best_g.first, make_pair(Nr[v], best_g.second));
      a_best_g.first.first += SumaFT(rozmiar + Pre[x].first);
      res = min(a_best_g, res);
    }
    v = Parent[0][x];
  }
  if (Poz[v].first <= Poz[u].second) {
    best_g =
        WezMin(Nr[v], 1, 0, Rozmiar[Nr[v]] - 1, Poz[v].first, Poz[u].second);
    a_best_g = make_pair(best_g.first, make_pair(Nr[v], best_g.second));
    a_best_g.first.first += SumaFT(rozmiar + Pre[Ost[Nr[v]]].first);
    return min(a_best_g, res);
  }
  return res;
}
int main() {
  pair<pair<long long, long long>, pair<int, int> > o;
  vector<int> Res;
  int n, m, q;
  int i, j;
  int w, t, v, u, k, lca;
  scanf("%d%d%d", &n, &m, &q);
  Wczytaj(n, m);
  Inicjuj(n);
  for (i = 0; i < q; i++) {
    scanf("%d", &t);
    if (t == 1) {
      Res.clear();
      scanf("%d%d%d", &v, &u, &k);
      lca = LCA(v, u);
      for (j = 0; j < k; j++) {
        o = min(BestGirl(v, lca), BestGirl(u, lca));
        if (o.first.first >= INF) break;
        Res.push_back(Sciezka[o.second.first][o.second.second].first);
        Dodaj(o.second.first, 1, 0, Rozmiar[o.second.first] - 1,
              o.second.second, o.second.second, make_pair(INF, INF));
      }
      printf("%d ", (int)Res.size());
      for (j = 0; j < Res.size(); j++) printf("%d ", Res[j]);
      printf("\n");
    }
    if (t == 2) {
      scanf("%d%d", &v, &w);
      if (Poz[v].second >= 0 && Ost[Nr[v]] != v)
        Dodaj(Nr[v], 1, 0, Rozmiar[Nr[v]] - 1, 0, Poz[v].second,
              make_pair((long long)w, 0));
      DodajFT(rozmiar + Pre[v].first, rozmiar + Pre[v].second, (long long)w);
    }
  }
  return 0;
}
