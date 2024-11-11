#include <bits/stdc++.h>
using namespace std;
char var[5010][15], aux[1010], sa[1010], sb[1010];
int v[5010][1010], op[5010];
int n, m, a[1010], b[5010], na, nb;
int readit() {
  if (aux[0] == '?') return -1;
  int j;
  for (j = 1; j < n; j++)
    if (strlen(aux) == strlen(var[j]) && strcmp(aux, var[j]) == 0) {
      return j;
    }
}
void solve(int i) {
  if (v[i][1] == -1 && v[i][2] == -1) {
    if (op[i] == 1) {
      a[i] = 0 ^ 0;
      b[i] = 1 ^ 1;
    }
    if (op[i] == 2) {
      a[i] = 0 | 0;
      b[i] = 1 | 1;
    }
    if (op[i] == 3) {
      a[i] = 0 & 0;
      b[i] = 1 & 1;
    }
  } else if (v[i][1] == -1) {
    if (op[i] == 1) {
      a[i] = 0 ^ a[v[i][2]];
      b[i] = 1 ^ b[v[i][2]];
    }
    if (op[i] == 2) {
      a[i] = 0 | a[v[i][2]];
      b[i] = 1 | b[v[i][2]];
    }
    if (op[i] == 3) {
      a[i] = 0 & a[v[i][2]];
      b[i] = 1 & b[v[i][2]];
    }
  } else {
    if (op[i] == 1) {
      a[i] = a[v[i][1]] ^ a[v[i][2]];
      b[i] = b[v[i][1]] ^ b[v[i][2]];
    }
    if (op[i] == 2) {
      a[i] = a[v[i][1]] | a[v[i][2]];
      b[i] = b[v[i][1]] | b[v[i][2]];
    }
    if (op[i] == 3) {
      a[i] = a[v[i][1]] & a[v[i][2]];
      b[i] = b[v[i][1]] & b[v[i][2]];
    }
  }
}
int main() {
  int i, j, x, y;
  scanf("%d %d\n", &n, &m);
  for (i = 1; i <= n; i++) {
    scanf("%s ", &var[i]);
    memset(aux, 0, sizeof(aux));
    scanf("%s ", &aux);
    memset(aux, 0, sizeof(aux));
    scanf("%s", &aux);
    if (aux[0] == '1' || aux[0] == '0') {
      for (j = 1; j <= m; j++) v[i][j] = aux[j - 1] - '0';
      continue;
    }
    v[i][1] = readit();
    memset(aux, 0, sizeof(aux));
    scanf("%s", &aux);
    if (aux[0] == 'X')
      op[i] = 1;
    else if (aux[0] == 'O')
      op[i] = 2;
    else
      op[i] = 3;
    memset(aux, 0, sizeof(aux));
    scanf("%s", &aux);
    v[i][2] = readit();
    if (v[i][2] == -1) swap(v[i][1], v[i][2]);
  }
  for (j = 1; j <= m; j++) {
    na = nb = 0;
    for (i = 1; i <= n; i++) {
      if (op[i] == 0) {
        a[i] = v[i][j];
        b[i] = v[i][j];
      } else
        solve(i);
      na += a[i];
      nb += b[i];
    }
    if (na < nb)
      sa[j - 1] = '0', sb[j - 1] = '1';
    else if (na > nb)
      sa[j - 1] = '1', sb[j - 1] = '0';
    else
      sa[j - 1] = '0', sb[j - 1] = '0';
  }
  printf("%s\n%s", sa, sb);
  return 0;
}
