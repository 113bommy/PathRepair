#include <bits/stdc++.h>
using namespace std;
int a, b, n, i, j, x, rez, l, r, u, d, m, nrb, lat, k, perm[200005], z[200005];
char c, t[200005], p[200005];
bool check(int delz) {
  int i;
  for (i = 1; i <= delz; i++) z[perm[i] - 1] = 1;
  int poz = 0;
  for (i = 0; i < n; i++)
    if (poz < m - 1 && z[i] == 0 && t[i] == p[poz]) poz++;
  for (i = 1; i <= delz; i++) z[perm[i] - 1] = 0;
  if (poz == m - 1) return 1;
  return 0;
}
int cautbin() {
  int pas = 1 << 29, rez = 0;
  while (pas) {
    if (pas + rez <= n && check(pas + rez)) rez += pas;
    pas /= 2;
  }
  return rez;
}
int main() {
  cin >> t >> p;
  n = strlen(t);
  m = strlen(p);
  for (i = 1; i <= n; i++) cin >> perm[i];
  cout << cautbin() << '\n';
  return 0;
}
