#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5 + 15;
int fg, G[15][15], i, j, n, k, ans = 0;
inline int Forj() {
  j++;
  fg && (scanf("%d", &G[i][j]) || 1);
  ans = max(ans, G[i][j]);
  return j != n ? Forj() : n;
}
inline int Fori() {
  i++;
  j = 0;
  Forj();
  return i != n ? Fori() : n;
}
inline int Forj1() {
  j++;
  G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
  return j != n ? Forj1() : n;
}
inline int Fori1() {
  i++;
  j = 0;
  Forj1();
  return i != n ? Fori1() : n;
}
inline int Fork() {
  k++;
  i = 0;
  Fori1();
  return k != n ? Fork() : n;
}
int main() {
  scanf("%d", &n);
  fg = 1;
  i = 0;
  Fori();
  k = 0;
  Fork();
  fg = 0;
  i = 0;
  ans = 0;
  Fori();
  cout << ans << endl;
  return 0;
}
