#include <bits/stdc++.h>
using namespace std;
int n, q;
int f[100005];
vector<pair<int, int> > E[100005];
pair<int, pair<int, int> > Q[100005];
vector<pair<int, int> > E2[100005];
int Size[100005];
pair<int, int> Par[100005];
void Rootaj(int id, int p) {
  Size[id] = 1;
  for (auto first : E[id])
    if (first.first != p) {
      E2[id].push_back(first);
      Rootaj(first.first, id);
      Size[id] += Size[first.first];
      Par[first.first] = {id, first.second};
    }
}
class Node {
 public:
  int l, r;
  int score;
  bool fill;
};
Node operator+(Node a, Node b) {
  if (a.fill && b.fill) return {a.l + b.l, a.l + b.l, 0, true};
  if (a.fill) return {a.l + b.l, b.r, b.score, false};
  if (b.fill) return {a.l, a.r + b.r, a.score, false};
  return {a.l, b.r, a.score + b.score + f[a.r + b.l], false};
}
int Val(Node a) {
  if (a.fill) return f[a.l];
  return a.score + f[a.l] + f[a.r];
}
const int offset = (1 << 20);
Node T[offset * 2];
void Set(int id, int lo, int hi, int p, bool v) {
  if (lo > p || hi < p) return;
  if (lo == hi) {
    if (v)
      T[id] = {1, 1, 0, true};
    else
      T[id] = {0, 0, 0, false};
    return;
  }
  int m = (lo + hi) / 2;
  Set(id * 2, lo, m, p, v);
  Set(id * 2 + 1, m + 1, hi, p, v);
  T[id] = T[id * 2] + T[id * 2 + 1];
}
void Set(int p, bool v) { Set(1, 0, offset - 1, p, v); }
Node Query(int id, int lo, int hi, int slo, int shi) {
  if (lo > shi || hi < slo) return {0, 0, 0, true};
  if (lo >= slo && hi <= shi) return T[id];
  int m = (lo + hi) / 2;
  return Query(id * 2, lo, m, slo, shi) +
         Query(id * 2 + 1, m + 1, hi, slo, shi);
}
Node Query(int lo, int hi) { return Query(1, 0, offset - 1, lo, hi); }
pair<int, int> Ch[100005];
int clr[100005];
int pos[100005];
int ChDep[100005];
int root[100005];
void Heavy(int id, int chain) {
  static int Cnt = 0;
  static int Cnt2 = 1;
  clr[id] = chain;
  pos[id] = Cnt++;
  Ch[chain].second = pos[id];
  if (E2[id].size() == 0) return;
  int opt = 0;
  for (int i = (int)(0); i < (int)(E2[id].size()); ++i)
    if (Size[E2[id][i].first] > Size[E2[id][opt].first]) opt = i;
  Heavy(E2[id][opt].first, chain);
  for (int i = (int)(0); i < (int)(E2[id].size()); ++i)
    if (i != opt) {
      int ch2 = Cnt2++;
      ChDep[ch2] = ChDep[chain] + 1;
      root[ch2] = E2[id][i].first;
      Ch[ch2].first = Cnt;
      Heavy(E2[id][i].first, ch2);
    }
}
Node Flip(Node a) { return {a.r, a.l, a.score, a.fill}; }
Node Get(int A, int B) {
  if (clr[A] == clr[B]) {
    if (Size[A] > Size[B]) return Query(pos[A] + 1, pos[B]);
    return Flip(Query(pos[B] + 1, pos[A]));
  }
  if (ChDep[clr[A]] > ChDep[clr[B]])
    return Flip(Query(Ch[clr[A]].first, pos[A])) +
           Get(Par[root[clr[A]]].first, B);
  else
    return Get(A, Par[root[clr[B]]].first) + Query(Ch[clr[B]].first, pos[B]);
}
int main() {
  scanf("%d%d", &n, &q);
  for (int i = (int)(1); i < (int)(n); ++i) scanf("%d", f + i);
  for (int i = (int)(0); i < (int)(n - 1); ++i) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c), --a, --b;
    E[a].push_back({b, c});
    E[b].push_back({a, c});
  }
  Rootaj(0, 0);
  Heavy(0, 0);
  for (int i = (int)(0); i < (int)(n); ++i) Set(i, true);
  for (int i = (int)(0); i < (int)(q); ++i)
    scanf("%d%d%d", &Q[i].second.first, &Q[i].second.second, &Q[i].first),
        --Q[i].second.first, --Q[i].second.second;
  vector<pair<int, int> > V;
  for (int i = (int)(0); i < (int)(q); ++i) V.push_back({Q[i].first, i});
  vector<pair<int, int> > V2;
  for (int i = (int)(0); i < (int)(n); ++i) V2.push_back({Par[i].second, i});
  sort(V.begin(), V.end());
  sort(V2.begin(), V2.end());
  vector<int> out(q);
  for (int i = 0, j = 0; i < (int)V.size(); ++i) {
    while (j < (int)V2.size() && V2[j].first < V[i].first)
      Set(pos[V2[j].second], false), ++j;
    out[V[i].second] =
        Val(Get(Q[V[i].second].second.first, Q[V[i].second].second.second));
  }
  for (auto first : out) printf("%d\n", first);
  return 0;
}
