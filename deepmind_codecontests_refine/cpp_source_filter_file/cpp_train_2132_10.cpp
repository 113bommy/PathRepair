#include <bits/stdc++.h>
using namespace std;
const int N = 300;
const int INF = 1000 * 1000 * 10;
vector<int> Graf[N];
vector<int> GrafN[N];
vector<int> Droga;
vector<int> Stoly[N];
int Pierwsza[N * N * 10];
int Przepustowosc[N][N];
int Dis[N];
int L[N];
int l_p, l_np;
void Sito(int n) {
  int i, j;
  Pierwsza[1] = 1;
  for (i = 2; i <= n; i++) {
    if (Pierwsza[i] == 0) {
      j = i + i;
      while (j < n) {
        Pierwsza[j] = 1;
        j += i;
      }
    }
  }
}
void DodajKraw(int v, int u) {
  Graf[v].push_back(u);
  Graf[u].push_back(v);
}
bool BFS(int s, int t, int n) {
  int i, v;
  queue<int> K;
  for (i = s; i <= t; i++) Dis[i] = -1;
  Dis[s] = 0;
  K.push(s);
  while (!K.empty()) {
    v = K.front();
    K.pop();
    for (i = 0; i < Graf[v].size(); i++) {
      if (Dis[Graf[v][i]] == -1 && Przepustowosc[v][Graf[v][i]] > 0) {
        K.push(Graf[v][i]);
        Dis[Graf[v][i]] = Dis[v] + 1;
      }
    }
  }
  return Dis[t] != -1;
}
int DFS(int v, int t, int przeplyw) {
  int res, koszt, i;
  if (v == t || przeplyw == 0) return przeplyw;
  res = 0;
  for (i = 0; i < Graf[v].size(); i++) {
    if (Dis[Graf[v][i]] - Dis[v] == 1 && Przepustowosc[v][Graf[v][i]] > 0) {
      koszt = DFS(Graf[v][i], t, min(Przepustowosc[v][Graf[v][i]], przeplyw));
      Przepustowosc[v][Graf[v][i]] -= koszt;
      Przepustowosc[Graf[v][i]][v] += koszt;
      przeplyw -= koszt;
      res += koszt;
      if (przeplyw == 0) break;
    }
  }
  return res;
}
int Dynic(int n) {
  int res;
  res = 0;
  while (BFS(0, n + 1, n)) {
    res += DFS(0, n + 1, INF);
  }
  return res;
}
void Wczytaj(int n) {
  int i, j;
  for (i = 1; i <= n; i++) {
    scanf("%d", &L[i]);
    if (L[i] % 2 == 0) {
      l_p++;
      DodajKraw(0, i);
      Przepustowosc[0][i] = 2;
    } else {
      l_np++;
      DodajKraw(n + 1, i);
      Przepustowosc[i][n + 1] = 2;
    }
  }
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      if (Pierwsza[L[i] + L[j]] == 0) {
        DodajKraw(i, j);
        if (L[i] % 2 == 0)
          Przepustowosc[i][j] = 1;
        else
          Przepustowosc[j][i] = 1;
      }
    }
  }
}
void DFSWpisz(int v) {
  int i;
  Dis[v] = 1;
  Droga.push_back(v);
  for (i = 0; i < GrafN[v].size(); i++) {
    if (Dis[GrafN[v][i]] == 0) DFSWpisz(GrafN[v][i]);
  }
}
void Wypisz(int n) {
  int i, j, st;
  st = 0;
  for (i = 1; i <= n; i++) Dis[i] = 0;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      if (L[i] % 2 == 1 && Przepustowosc[i][j] == 1) {
        GrafN[i].push_back(j);
        GrafN[j].push_back(i);
      }
    }
  }
  for (i = 1; i <= n; i++) {
    if (Dis[i] == 0) {
      st++;
      Droga.clear();
      DFSWpisz(i);
      Stoly[i] = Droga;
    }
  }
  printf("%d\n", st);
  for (i = 1; i <= n; i++) {
    if (Stoly[i].size() > 0) {
      printf("%d ", (int)Stoly[i].size());
      for (j = 0; j < Stoly[i].size(); j++) printf("%d ", Stoly[i][j]);
      printf("\n");
    }
  }
}
int main() {
  Sito(100 * 100);
  int n, przeplyw, i, j;
  scanf("%d", &n);
  Wczytaj(n);
  przeplyw = Dynic(n);
  if (przeplyw == l_p * 2 && przeplyw == l_np * 2)
    Wypisz(n);
  else
    printf("Impossible\n");
  return 0;
}
