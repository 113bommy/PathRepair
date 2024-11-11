#include <bits/stdc++.h>
using namespace std;
long n, m;
string st;
long bst, bc, ans;
long qi, qj, ti, tj;
vector<vector<long> > u, l, r, d, ar;
void dodel(long a, long b) {
  if (l[a][b] != -1) {
    r[a][l[a][b]] = r[a][b];
  }
  if (r[a][b] != -1) {
    l[a][r[a][b]] = l[a][b];
  }
  if (u[a][b] != -1) {
    d[u[a][b]][b] = d[a][b];
  }
  if (d[a][b] != -1) {
    u[d[a][b]][b] = u[a][b];
  }
}
bool outside(long a, long b) { return (a == -1 || b == -1); }
long gi(long a, long b) {
  if (ar[a][b] == 'L' || ar[a][b] == 'R') return a;
  if (ar[a][b] == 'U') return u[a][b];
  return d[a][b];
}
long gj(long a, long b) {
  if (ar[a][b] == 'D' || ar[a][b] == 'U') return b;
  if (ar[a][b] == 'L') return l[a][b];
  return r[a][b];
}
void recalc() {
  long ls = -1;
  for (int i = 1; i <= n; i++) {
    ls = -1;
    for (int j = 1; j <= m; j++) {
      l[i][j] = ls;
      if (ar[i][j]) ls = j;
    }
  }
  for (int i = 1; i <= n; i++) {
    ls = -1;
    for (int j = m; j >= 1; j--) {
      r[i][j] = ls;
      if (ar[i][j]) ls = j;
    }
  }
  for (int j = 1; j <= m; j++) {
    ls = -1;
    for (int i = 1; i <= n; i++) {
      u[i][j] = ls;
      if (ar[i][j]) ls = i;
    }
  }
  for (int j = 1; j <= m; j++) {
    ls = -1;
    for (int i = n; i; i--) {
      d[i][j] = ls;
      if (ar[i][j]) ls = i;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  ar.resize(n + 5);
  for (int i = 0; i < ar.size(); i++) ar[i].resize(m + 5);
  l.resize(n + 5);
  for (int i = 0; i < l.size(); i++) l[i].resize(m + 5);
  r.resize(n + 5);
  for (int i = 0; i < r.size(); i++) r[i].resize(m + 5);
  u.resize(n + 5);
  for (int i = 0; i < u.size(); i++) u[i].resize(m + 5);
  d.resize(n + 5);
  for (int i = 0; i < d.size(); i++) d[i].resize(m + 5);
  for (int i = 1; i <= n; i++) {
    cin >> st;
    for (int j = 1; j <= m; j++) {
      if (st[j - 1] != '.')
        ar[i][j] = st[j - 1];
      else
        ar[i][j] = 0;
    }
  }
  bst = -1;
  bc = -1;
  for (int ri = 1; ri <= n; ri++)
    for (int rj = 1; rj <= m; rj++) {
      if (ar[ri][rj] == 0) continue;
      recalc();
      qi = ri;
      qj = rj;
      ans = 1;
      while (true) {
        ti = gi(qi, qj);
        tj = gj(qi, qj);
        dodel(qi, qj);
        if (outside(ti, tj)) break;
        qi = ti;
        qj = tj;
        ++ans;
      }
      if (ans >= bst) {
        if (ans == bst)
          bc++;
        else
          bc = 1;
        bst = ans;
      }
    }
  cout << bst << " " << bc << endl;
  cin.get();
  cin.get();
  return 0;
}
