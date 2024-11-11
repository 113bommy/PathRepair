#include <bits/stdc++.h>
using namespace std;
int n, m, first = -1, second, ans;
char grid[1010][1010], aux[1010][1010];
bool desce(int px, int py, int tt) {
  return (px + tt < n) && (grid[px + tt][py] == 'X');
}
bool dir(int px, int py, int tt = 1) {
  return (py + tt < m) && (grid[px][py + tt] == 'X');
}
int acha_dir(int px, int py) {
  int ret = 0;
  while (py < m && grid[px][py] == 'X') ret++, py++;
  return ret;
}
void testa(int px, int py, int tt, int tl) {
  memset(aux, 0, sizeof(aux));
  while (1) {
    aux[px][py] = 1;
    if (desce(px, py, tt))
      px++;
    else if (dir(px, py, tl))
      py++;
    else
      break;
  }
  for (int(i) = (0); (i) < (n); (i)++) {
    int ult = -1e5;
    for (int(j) = (0); (j) < (m); (j)++)
      if (aux[i][j] == 1)
        ult = j;
      else if (ult + tl - 1 >= j)
        aux[i][j] = 2;
  }
  for (int(j) = (0); (j) < (m); (j)++) {
    int ult = -1e5;
    for (int(i) = (0); (i) < (n); (i)++)
      if (aux[i][j] && aux[i][j] < 3)
        ult = i;
      else if (ult + tt - 1 >= i)
        aux[i][j] = 3;
  }
  for (int(i) = (0); (i) < (n); (i)++)
    for (int(j) = (0); (j) < (m); (j)++)
      if ((aux[i][j] && grid[i][j] != 'X') || (!aux[i][j] && grid[i][j] == 'X'))
        return;
  ans = min(ans, tt * tl);
}
void solve() {
  int tt = 0;
  for (int(i) = (first); (i) < (n); (i)++)
    if (grid[i][second] == 'X')
      tt++;
    else
      break;
  int px = first, py = second;
  int tl = -1;
  while (1) {
    if (desce(px, py, tt)) {
      int cl = acha_dir(px, py);
      if (cl != tl && tl != -1) return;
      tl = cl;
      if (!tl) return;
      px++;
    } else if (dir(px, py))
      py++;
    else
      break;
  }
  if (tl == -1) tl = 1;
  testa(first, second, tt, tl);
}
int main() {
  ans = 1e7;
  scanf("%d%d", &n, &m);
  for (int(i) = (0); (i) < (n); (i)++) scanf("%s", grid[i]);
  for (int(i) = (0); (i) < (n); (i)++)
    if (first == -1)
      for (int(j) = (0); (j) < (m); (j)++)
        if (grid[i][j] == 'X') {
          first = i, second = j;
          break;
        }
  solve();
  for (int(i) = (0); (i) < (n); (i)++)
    for (int(j) = (0); (j) < (m); (j)++) aux[j][i] = grid[i][j];
  swap(n, m);
  for (int(i) = (0); (i) < (n); (i)++)
    for (int(j) = (0); (j) < (m); (j)++) grid[i][j] = aux[i][j];
  swap(first, second);
  solve();
  if (ans > 2e6) ans = -1;
  printf("%d\n", ans);
}
