#include <bits/stdc++.h>
using namespace std;
int i, j, n, m, b, c, d, op, maxi, mini, mij, ls, ld, ul, timp, k, maxl, rasp;
int v[1000005];
long long a[2000005];
void update(int poz, int val, int st, int dr, int op) {
  int mij = (st + dr) / 2;
  if (st == dr) {
    a[poz] += op;
    return;
  }
  if (mij >= val)
    update(poz * 2, val, st, mij, op);
  else
    update(poz * 2 + 1, val, mij + 1, dr, op);
  a[poz] = a[poz * 2] + a[poz * 2 + 1];
}
void query(int poz, int val, int st, int dr, long long &rez) {
  int mij = (st + dr) / 2;
  if (dr < val) return;
  if (st >= val) {
    rez += a[poz];
    return;
  }
  query(poz * 2, val, st, mij, rez);
  query(poz * 2 + 1, val, mij + 1, dr, rez);
}
long long solve(int first) {
  for (int i = 0; i <= 2000004; i++) a[i] = 0;
  long long rez = 0;
  int a = 0;
  for (int i = 1; i <= n; i++) {
    if (v[i] < first)
      a--;
    else
      a++;
    update(1, a + 200000, 0, 400000, 1);
  }
  a = 0;
  query(1, 200000 + a, 0, 400000, rez);
  for (int i = 1; i <= n; i++) {
    if (v[i] < first)
      a--;
    else
      a++;
    update(1, a + 200000, 0, 400000, -1);
    query(1, 200001 + a, 0, 400000, rez);
  }
  return rez;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> v[i];
  cout << solve(m) - solve(m + 1);
  return 0;
}
