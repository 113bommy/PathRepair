#include <bits/stdc++.h>
using namespace std;
const int NMax = 1005;
int N, cntH, cntV;
vector<int> G[NMax];
struct Line {
  int x1, x2, y;
} HorizL[NMax], VertL[NMax];
pair<int, int> P[NMax];
bool Use[NMax];
int L[NMax], R[NMax];
bool UseR[NMax], UseL[NMax];
void Read() {
  cin >> N;
  for (int i = 1; i <= N; i++) cin >> P[i].first >> P[i].second;
}
inline bool cmpOrd(pair<int, int> a, pair<int, int> b) {
  if (a.second == b.second) return a.first < b.first;
  return a.second < b.second;
}
void sortByOrd() { sort(P + 1, P + N + 1, cmpOrd); }
void sortByAbs() { sort(P + 1, P + N + 1); }
void buildHorizLines() {
  sortByOrd();
  for (int i = 1; i < N; i++) {
    if (P[i].second == P[i + 1].second)
      HorizL[++cntH] = {P[i].first, P[i + 1].first, P[i].second};
    else
      HorizL[++cntH] = {P[i].first, P[i].first, P[i].second};
  }
  HorizL[++cntH] = {P[N].first, P[N].first, P[N].second};
}
void buildVertLines() {
  sortByAbs();
  for (int i = 1; i < N; i++) {
    if (P[i].first == P[i + 1].first)
      VertL[++cntV] = {P[i].second, P[i + 1].second, P[i].first};
    else
      VertL[++cntV] = {P[i].second, P[i].second, P[i].first};
  }
  VertL[++cntV] = {P[N].second, P[N].second, P[N].first};
}
inline bool Intersects(int horiz, int vert) {
  return HorizL[horiz].y > VertL[vert].x1 && HorizL[horiz].y < VertL[vert].x2 &&
         VertL[vert].y > HorizL[horiz].x1 && VertL[vert].y < HorizL[horiz].x2;
}
void buildGraph() {
  for (int i = 1; i <= cntH; i++) {
    for (int j = 1; j <= cntV; j++)
      if (Intersects(i, j)) {
        G[i].push_back(j);
      }
  }
}
bool pairup(int n) {
  unsigned int i = 0;
  if (Use[n] == 1) return 0;
  Use[n] = 1;
  for (i = 0; i < G[n].size(); i++) {
    int vecin = G[n][i];
    if (R[vecin] == 0) {
      R[vecin] = n;
      L[n] = vecin;
      return 1;
    }
  }
  for (i = 0; i < G[n].size(); i++) {
    int vecin = G[n][i];
    if (pairup(R[vecin]) == 1) {
      R[vecin] = n;
      L[n] = vecin;
      return 1;
    }
  }
  return 0;
}
void Matching() {
  int i, cuplaj = 0;
  bool change = 1;
  while (change == 1) {
    change = 0;
    memset(Use, 0, sizeof(Use));
    for (i = 1; i <= cntH; i++)
      if (L[i] == 0) change |= pairup(i);
  }
}
void DFS(int node) {
  UseL[node] = 1;
  for (int i = 0; i < G[node].size(); i++) {
    int neighb = G[node][i];
    UseR[neighb] = 1;
    if (R[neighb] != 0 && UseL[R[neighb]] == 0) DFS(R[neighb]);
  }
}
void printH(int horiz) {
  cout << HorizL[horiz].x1 << " " << HorizL[horiz].y << " " << HorizL[horiz].x2
       << " " << HorizL[horiz].y << "\n";
}
void printV(int vert) {
  cout << VertL[vert].y << " " << VertL[vert].x1 << " " << VertL[vert].y << " "
       << VertL[vert].x2 << "\n";
}
void printHoriz() {
  int nb = 0;
  int currl = HorizL[1].y;
  pair<int, int> res = make_pair(HorizL[1].x1, HorizL[1].x2);
  vector<Line> Sol;
  for (int i = 1; i <= cntH; i++) {
    if (UseL[i] == 0) {
      if (currl != 0) Sol.push_back({res.first, res.second, currl});
      if (currl != HorizL[i].y)
        Sol.push_back({HorizL[i].x1, HorizL[i].x1, HorizL[i].y});
      res = make_pair(HorizL[i].x2, HorizL[i].x2), currl = HorizL[i].y;
      continue;
    }
    if (res.second == HorizL[i].x1 && currl == HorizL[i].y)
      res.second = HorizL[i].x2;
    else {
      if (currl != 0) Sol.push_back({res.first, res.second, currl});
      res = make_pair(HorizL[i].x1, HorizL[i].x2), currl = HorizL[i].y;
    }
  }
  if (currl != 0) Sol.push_back({res.first, res.second, currl});
  cout << Sol.size() << "\n";
  for (int i = 0; i < Sol.size(); i++)
    cout << Sol[i].x1 << " " << Sol[i].y << " " << Sol[i].x2 << " " << Sol[i].y
         << "\n";
}
void printVert() {
  int currl = VertL[1].y;
  pair<int, int> res = make_pair(VertL[1].x1, VertL[1].x2);
  vector<Line> Sol;
  for (int i = 1; i <= cntV; i++) {
    if (UseR[i] == 1) {
      if (currl != 0) Sol.push_back({res.first, res.second, currl});
      if (currl != VertL[i].y)
        Sol.push_back({VertL[i].x1, VertL[i].x1, VertL[i].y});
      res = make_pair(VertL[i].x2, VertL[i].x2), currl = VertL[i].y;
      continue;
    }
    if (res.second == VertL[i].x1 && currl == VertL[i].y)
      res.second = VertL[i].x2;
    else {
      if (currl != 0) Sol.push_back({res.first, res.second, currl});
      res = make_pair(VertL[i].x1, VertL[i].x2), currl = VertL[i].y;
    }
  }
  if (currl != 0) Sol.push_back({res.first, res.second, currl});
  cout << Sol.size() << "\n";
  for (int i = 0; i < Sol.size(); i++)
    cout << Sol[i].y << " " << Sol[i].x1 << " " << Sol[i].y << " " << Sol[i].x2
         << "\n";
}
void MVC() {
  for (int i = 1; i <= cntH; i++)
    if (L[i] == 0) DFS(i);
  printHoriz();
  printVert();
}
int main() {
  Read();
  buildHorizLines();
  buildVertLines();
  buildGraph();
  Matching();
  MVC();
  return 0;
}
