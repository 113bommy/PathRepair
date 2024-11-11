#include <bits/stdc++.h>
using namespace std;
void scanint(int &x) {
  int c = getchar_unlocked();
  x = 0;
  while (((c < 48 || c > 57))) c = getchar_unlocked();
  for (; c > 47 && c < 58; c = getchar_unlocked()) {
    x = (x << 1) + (x << 3) + c - 48;
  }
}
const int N = (1 << 19), ZAS = 2e5 + 100;
struct Node {
  int a, b, c;
};
int n, m, q, Time, wynik[N], R[N], ile[N], edgeUp[N], PreviousValue[10 * N],
    *Where[10 * N];
map<pair<int, int>, pair<int, int> > mapa;
pair<int, int> Query[N];
vector<Node> Edges[5 * N + 400];
vector<int> Basis;
inline void RollBack(int TargetTime) {
  while (Time != TargetTime) {
    Time--;
    (*Where[Time]) = PreviousValue[Time];
  }
}
inline void Change(int &variable, int to) {
  Where[Time] = &variable;
  PreviousValue[Time] = variable;
  Time++;
  variable = to;
}
inline void InsertEdge(int v, int l, int r, int A, int B, int a, int b, int c) {
  if (r < A || l > B || l > r) return;
  if (A <= l && r <= B) {
    Edges[v].push_back({a, b, c});
    return;
  }
  int mid = (l + r) / 2;
  InsertEdge(2 * v, l, mid, A, B, a, b, c);
  InsertEdge(2 * v + 1, mid + 1, r, A, B, a, b, c);
}
int Find(int w) { return (R[w] == w) ? w : R[w] = Find(R[w]); }
int FindXOR(int w) { return (R[w] == w) ? 0 : edgeUp[w] ^ FindXOR(R[w]); }
inline void AddToBasis(int x) {
  for (auto v : Basis) x = min(x, x ^ v);
  if (x != 0) {
    for (auto &v : Basis) v = min(v, v ^ x);
    Basis.push_back(x);
    sort(Basis.rbegin(), Basis.rend());
  }
}
inline int Minimize(int x) {
  for (auto v : Basis) x = min(x, x ^ v);
  return x;
}
inline void Union(int a, int b, int c) {
  int distA = FindXOR(a);
  int distB = FindXOR(b);
  a = Find(a);
  b = Find(b);
  if (a == b)
    AddToBasis(distA ^ distB ^ c);
  else {
    c = distA ^ distB ^ c;
    if (ile[a] > ile[b]) swap(a, b);
    Change(R[a], b);
    Change(edgeUp[a], c);
    if (ile[a] == ile[b]) Change(ile[b], ile[b] + 1);
  }
}
inline void DFS(int v, int l, int r) {
  vector<int> TempBasis = Basis;
  int RollBackTime = Time;
  for (auto kraw : Edges[v]) Union(kraw.a, kraw.b, kraw.c);
  if (l == r) {
    if (Query[l] != make_pair(0, 0))
      printf("%d\n",
             Minimize(FindXOR(Query[l].first) ^ FindXOR(Query[l].second)));
  } else {
    int mid = (l + r) / 2;
    DFS(2 * v, l, mid);
    DFS(2 * v + 1, mid + 1, r);
  }
  RollBack(RollBackTime);
  Basis = TempBasis;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) R[i] = i, ile[i] = 1, edgeUp[i] = 0;
  for (int i = 1; i <= m; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if (a > b) swap(a, b);
    mapa[make_pair(a, b)] = make_pair(0, c);
  }
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) {
    int typ, a, b;
    scanf("%d%d%d", &typ, &a, &b);
    if (a > b) swap(a, b);
    if (typ == 1) {
      int c;
      scanf("%d", &c);
      mapa[make_pair(a, b)] = make_pair(i, c);
    } else if (typ == 2) {
      pair<int, int> odczyt = mapa[make_pair(a, b)];
      InsertEdge(1, 0, q, odczyt.first, i - 1, a, b, odczyt.second);
      mapa.erase(make_pair(a, b));
    } else if (typ == 3)
      Query[i] = make_pair(a, b);
  }
  for (auto v : mapa)
    InsertEdge(1, 0, q, v.second.first, q, v.first.first, v.first.second,
               v.second.second);
  DFS(1, 0, q);
  getchar();
  getchar();
  return 0;
}
