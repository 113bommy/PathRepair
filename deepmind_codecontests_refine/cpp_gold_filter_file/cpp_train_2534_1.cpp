#include <bits/stdc++.h>
using namespace std;
struct pkt {
  long long x, y;
  int nr;
};
int n;
void dfs(vector<vector<int> >& T, vector<int>& wlk, int akt, int oj) {
  for (int i = 0; i < T[akt].size(); ++i)
    if (T[akt][i] != oj) dfs(T, wlk, T[akt][i], akt);
  if (T[akt].size() == 1 && akt != 0)
    wlk[akt] = 1;
  else {
    wlk[akt] = 1;
    for (int i = 0; i < T[akt].size(); ++i)
      if (T[akt][i] != oj) wlk[akt] += wlk[T[akt][i]];
  }
}
int Cwiartka(pkt a) {
  if (a.x > 0 && a.y >= 0) return 0;
  if (a.x <= 0 && a.y > 0) return 1;
  if (a.x < 0 && a.y <= 0) return 2;
  if (a.x >= 0 && a.y < 0) return 3;
}
bool porownanie(pkt a, pkt b) {
  int cwA = Cwiartka(a);
  int cwB = Cwiartka(b);
  if (cwA != cwB) {
    if (cwA < cwB) return true;
    return false;
  } else {
    long long ay = abs(a.y), ax = abs(a.x);
    long long by = abs(b.y), bx = abs(b.x);
    if (cwA == 0 || cwA == 2) {
      if (ay * bx < ax * by) return true;
      return false;
    } else {
      if (ay * bx > ax * by) return true;
      return false;
    }
  }
}
void Sortuj(vector<pkt>& p, pkt s) {
  for (int i = 0; i < p.size(); ++i) {
    p[i].x -= s.x;
    p[i].y -= s.y;
  }
  sort(p.begin(), p.end(), porownanie);
  for (int i = 0; i < p.size(); ++i) {
    p[i].x += s.x;
    p[i].y += s.y;
  }
}
void Solve(vector<vector<int> >& T, vector<pkt> p, vector<int>& wlk, int akt,
           int oj, vector<int>& odp) {
  pkt sr = {-1, -1, -1};
  int x = -1;
  for (int i = 0; i < p.size(); ++i) {
    if (x == -1 || p[i].y < sr.y || (p[i].y == sr.y && p[i].x < sr.x)) {
      sr = p[i];
      x = i;
    }
  }
  vector<pkt> p2;
  for (int i = 0; i < p.size(); ++i)
    if (i != x) p2.push_back(p[i]);
  p = p2;
  odp[sr.nr] = akt;
  Sortuj(p, sr);
  int nr = 0;
  for (int i = 0; i < T[akt].size(); ++i) {
    if (T[akt][i] != oj) {
      vector<pkt> t;
      for (int j = nr; j <= nr + wlk[T[akt][i]] - 1; ++j) t.push_back(p[j]);
      Solve(T, t, wlk, T[akt][i], akt, odp);
      nr += wlk[T[akt][i]];
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  vector<vector<int> > T(n);
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    T[a].push_back(b);
    T[b].push_back(a);
  }
  vector<pkt> P(n);
  for (int i = 0; i < n; ++i) {
    cin >> P[i].x >> P[i].y;
    P[i].nr = i;
  }
  vector<int> wlk(n);
  dfs(T, wlk, 0, -1);
  vector<int> odp(n);
  Solve(T, P, wlk, 0, -1, odp);
  for (int i = 0; i < n; ++i) cout << odp[i] + 1 << " ";
  return 0;
}
