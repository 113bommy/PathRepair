#include <bits/stdc++.h>
using namespace std;
ifstream f("wow.in");
set<pair<pair<int, int>, int> > Seg;
set<pair<pair<int, int>, int> >::iterator it, iti;
int Arb[20][100666], t[100666];
long long SPMAX[20][100666], SPR[20][100666];
long long MAX[100666], R[100666], result;
int S[100666], lmax;
bool comp(int i1, int i2) { return t[i1] < t[i2]; }
void build_tree(int st, int dr, int nod, int lev) {
  for (int i = st; i <= dr; ++i) Arb[lev][i] = i;
  if (st == dr) return;
  sort(Arb[lev] + st, Arb[lev] + dr + 1, comp);
  int mij = (st + dr) / 2;
  build_tree(st, mij, nod * 2, lev + 1);
  build_tree(mij + 1, dr, nod * 2 + 1, lev + 1);
  lmax = max(lmax, lev);
}
pair<pair<int, int>, int> mk3(int i1, int i2, int i3) {
  return make_pair(make_pair(i1, i2), i3);
}
int bs(int st, int dr, int tval, int lev) {
  int pos, step;
  for (step = 1; step <= (dr - st + 1); step <<= 1)
    ;
  for (pos = st - 1; step; step >>= 1)
    if (pos + step <= dr && t[Arb[lev][pos + step]] <= tval) pos += step;
  return pos;
}
void query(int st, int dr, int nod, int X, int Y, int timp, int lev) {
  if (st >= X && dr <= Y) {
    int P = bs(st, dr, timp, lev);
    result += SPMAX[lev][P] - SPMAX[lev][st - 1];
    result += (SPR[lev][dr] - SPR[lev][P]) * timp;
    return;
  }
  int mij = (st + dr) / 2;
  if (mij >= X) query(st, mij, nod * 2, X, Y, timp, lev + 1);
  if (mij + 1 <= Y) query(mij + 1, dr, nod * 2 + 1, X, Y, timp, lev + 1);
}
int main() {
  int n, m, i;
  cin >> n;
  for (i = 1; i <= n; ++i) {
    cin >> S[i] >> MAX[i] >> R[i];
    if (R[i] == 0)
      t[i] = (1 << 30);
    else
      t[i] = MAX[i] / R[i] + (MAX[i] % R[i] ? 1 : 0);
    Seg.insert(mk3(i, i, -1));
  }
  build_tree(1, n, 1, 0);
  cin >> m;
  vector<pair<pair<int, int>, int> > X2;
  for (i = 0; i <= lmax; ++i)
    for (int j = 1; j <= n; ++j) {
      SPMAX[i][j] = SPMAX[i][j - 1] + MAX[Arb[i][j]];
      SPR[i][j] = SPR[i][j - 1] + R[Arb[i][j]];
    }
  for (i = 1; i <= m; ++i) {
    int timp, st, dr;
    cin >> timp >> st >> dr;
    it = Seg.lower_bound(mk3(st, -1, -3));
    if (it == Seg.end())
      --it;
    else if ((*it).first.first != st)
      --it;
    iti = it;
    X2.clear();
    result = 0;
    for (; it != Seg.end() && (*it).first.first <= dr; ++it) {
      pair<pair<int, int>, int> X = *it;
      int st2 = X.first.first, dr2 = X.first.second, timp2 = X.second;
      if (st2 < st) X2.push_back(mk3(st2, st - 1, timp2));
      if (dr2 > dr) X2.push_back(mk3(dr + 1, dr2, timp2));
      long long resi = result;
      if (timp2 != -1)
        query(1, n, 1, max(st, st2), min(dr, dr2), timp - timp2, 0);
      else
        result += min(S[st2] + R[st2] * timp, MAX[st2]);
    }
    Seg.erase(iti, it);
    for (unsigned int j = 0; j < X2.size(); ++j) Seg.insert(X2[j]);
    Seg.insert(mk3(st, dr, timp));
    cout << result << '\n';
  }
  return 0;
}
