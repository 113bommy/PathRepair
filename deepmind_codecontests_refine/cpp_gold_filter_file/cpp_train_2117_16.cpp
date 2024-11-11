#include <bits/stdc++.h>
using namespace std;
typedef struct event {
  int st, dr, t, tip, ind;
} EVENT;
EVENT E[200005];
int n, i, m, nr, B[400005], A[1600005], Rez[100005];
set<pair<int, int> > S[1600005];
void upd(int nod, int st, int dr, int poz, int val, int ind) {
  if (st == dr) {
    S[nod].insert({val, ind});
    A[nod] = (*S[nod].rbegin()).first;
    return;
  }
  int mij = (st + dr) / 2;
  if (poz <= mij)
    upd(2 * nod, st, mij, poz, val, ind);
  else
    upd(2 * nod + 1, mij + 1, dr, poz, val, ind);
  A[nod] = max(A[2 * nod], A[2 * nod + 1]);
}
void qry(int nod, int st, int dr, int l, int r, int ind) {
  if (st == dr) {
    while (!S[nod].empty()) {
      if ((*S[nod].rbegin()).first < l) break;
      Rez[(*S[nod].rbegin()).second] = ind;
      S[nod].erase(*S[nod].rbegin());
    }
    if (S[nod].empty())
      A[nod] = 0;
    else
      A[nod] = (*S[nod].rbegin()).first;
    return;
  }
  int mij = (st + dr) / 2;
  if (A[2 * nod] >= l) qry(2 * nod, st, mij, l, r, ind);
  if (A[2 * nod + 1] >= l && r > mij) qry(2 * nod + 1, mij + 1, dr, l, r, ind);
  A[nod] = max(A[2 * nod], A[2 * nod + 1]);
}
int src(int val) {
  int rez = 0, i;
  for (i = 18; i >= 0; i--)
    if (rez + (1 << i) <= nr && B[rez + (1 << i)] <= val) rez = rez + (1 << i);
  return rez;
}
bool cmp(EVENT a, EVENT b) {
  if (a.t != b.t) return a.t < b.t;
  return a.tip < b.tip;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (i = 1; i <= n; i++) {
    cin >> E[i].st >> E[i].dr >> E[i].t;
    E[i].tip = 1;
    E[i].ind = i;
    B[++nr] = E[i].st;
    B[++nr] = E[i].dr;
  }
  for (i = 1; i <= m; i++) {
    cin >> E[n + i].st >> E[n + i].dr >> E[n + i].t;
    E[n + i].ind = i;
    B[++nr] = E[n + i].st;
    B[++nr] = E[n + i].dr;
    Rez[i] = -1;
  }
  sort(B + 1, B + nr + 1);
  for (i = 1; i <= n + m; i++) {
    E[i].st = src(E[i].st);
    E[i].dr = src(E[i].dr);
  }
  sort(E + 1, E + n + m + 1, cmp);
  for (i = 1; i <= n + m; i++) {
    if (E[i].tip == 0)
      upd(1, 1, nr, E[i].dr, E[i].st, E[i].ind);
    else
      qry(1, 1, nr, E[i].st, E[i].dr, E[i].ind);
  }
  for (i = 1; i <= m; i++) cout << Rez[i] << " ";
  cout << "\n";
  return 0;
}
