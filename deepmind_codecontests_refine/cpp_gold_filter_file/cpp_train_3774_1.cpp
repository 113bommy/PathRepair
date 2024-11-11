#include <bits/stdc++.h>
using namespace std;
int n, m;
char str[11][11], ch;
bool is_valid(int t_ind) {
  ch = '0';
  for (int i = 1; i < n; i++) {
    int cont = 0;
    for (int j = 0; j < m; j++) {
      if (j == t_ind) continue;
      cont += (str[0][j] != str[i][j]);
    }
    if (cont > 1) return false;
    if (cont == 1 && t_ind >= 0) {
      if (ch != '0' && ch != str[i][t_ind]) return false;
      ch = str[i][t_ind];
    }
  }
  return true;
}
int main() {
  int tcase;
  scanf("%d", &tcase);
  while (tcase--) {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
      scanf("%s", str[i]);
    }
    if (is_valid(-1))
      printf("%s\n", str[0]);
    else {
      bool flag = true;
      for (int i = 0; i < m; i++) {
        if (is_valid(i)) {
          str[0][i] = ch;
          printf("%s\n", str[0]);
          flag = false;
          break;
        }
      }
      if (flag) puts("-1");
    }
  }
  return 0;
}
