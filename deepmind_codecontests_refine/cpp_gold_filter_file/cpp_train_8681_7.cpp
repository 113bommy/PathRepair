#include <bits/stdc++.h>
using namespace std;
char str[200][200], str2[200][200];
struct {
  int k, l;
  int u, v;
} a[200];
int main() {
  int m, x = 0;
  scanf("%d", &m);
  for (int i = 0; i < m; i++) scanf("%s", str[i]);
  for (int i = 0; i < m; i++)
    for (int j = 0; j < m; j++)
      if (str[i][j] == '.') {
        a[x].k = i + 1;
        a[x].l = j + 1;
        x++;
        break;
      }
  if (x == m) {
    for (int i = 0; i < m; i++) cout << a[i].k << " " << a[i].l << endl;
    return 0;
  }
  for (int i = 0; i < m; i++)
    for (int j = 0; j < m; j++) str2[j][i] = str[i][j];
  x = 0;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < m; j++)
      if (str2[i][j] == '.') {
        a[x].u = j + 1;
        a[x].v = i + 1;
        x++;
        break;
      }
  if (x == m) {
    for (int i = 0; i < m; i++) cout << a[i].u << " " << a[i].v << endl;
    return 0;
  }
  cout << -1 << endl;
  return 0;
}
