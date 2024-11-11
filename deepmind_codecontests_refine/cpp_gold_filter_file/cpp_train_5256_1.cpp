#include <bits/stdc++.h>
const int C = 200001, D = 26;
int sget2(char tab[]) {
  bool ff = 0;
  for (int z = 0;; z++) {
    tab[z] = getchar();
    if (tab[z] > 32) ff = 1;
    if (tab[z] <= 32 && ff == 1)
      return z;
    else if (tab[z] <= 32)
      z--;
  }
}
int p[C], p2[C], pt[C][D], ptb[C][D], fst[26];
int changepat(char tab[], int a, int k, int b) {
  int i, j;
  for (i = 0; i < D; i++) pt[a][i] = -1;
  for (i = 0; i < D; i++) {
    if (fst[i] <= k && fst[i] != -1) {
      if (pt[a][tab[a - k + b + fst[i]] - 97] != -1 &&
          pt[a][tab[a - k + b + fst[i]] - 97] != i)
        return 0;
      if (pt[a][i] != -1 && pt[a][i] != tab[a - k + b + fst[i]] - 97) return 0;
      pt[a][tab[a - k + b + fst[i]] - 97] = i;
      pt[a][i] = tab[a - k + b + fst[i]] - 97;
    }
  }
  return 1;
}
int eq(char tab[], char tab2[], int a, int b) {
  if (pt[a][tab[a] - 97] == tab2[b] - 97) return 1;
  if (pt[a][tab[a] - 97] == -1 && pt[a][tab2[b] - 97] == -1) return 1;
  return 0;
}
void chpat(char tab[], int a, int k, int b) {
  int i, j;
  for (i = 0; i < D; i++) pt[a][i] = -1, ptb[a][i] = -1;
  for (i = 0; i < D; i++) {
    if (fst[i] <= k && fst[i] != -1) {
      pt[a][tab[a - k + b + fst[i]] - 97] = i;
      ptb[a][i] = tab[a - k + b + fst[i]] - 97;
    }
  }
}
int eqp(char tab[], int a, int b) {
  if (pt[a][tab[a] - 97] == tab[b] - 97) return 1;
  if (pt[a][tab[a] - 97] == -1 && ptb[a][tab[b] - 97] == -1) return 1;
  return 0;
}
void KM(char tab[], int n) {
  int i, j;
  p[0] = -1;
  for (i = 0; i < D; i++) pt[0][i] = -1, ptb[0][i] = -1, fst[i] = -1;
  fst[tab[0] - 97] = 0;
  for (i = 1; i < n; i++) {
    p[i] = p[i - 1];
    if (fst[tab[i] - 97] == -1) fst[tab[i] - 97] = i;
    for (j = 0; j < D; j++) pt[i][j] = pt[i - 1][j], ptb[i][j] = ptb[i - 1][j];
    for (; p[i] > -1; p[i] = p[p[i]], chpat(tab, i, p[i], -1))
      if (eqp(tab, i, p[i] + 1)) break;
    if (eqp(tab, i, p[i] + 1)) {
      chpat(tab, i, p[i] + 1, 0);
      p[i]++;
    }
  }
}
void FindStr(char tab1[], int n1, char tab2[], int n2, int p[], int p2[]) {
  int j = -1, i, jj;
  for (i = 0; i < D; i++) pt[0][i] = -1;
  for (int i = 0; i < n1; i++) {
    if (i > 0)
      for (jj = 0; jj < D; jj++) pt[i][jj] = pt[i - 1][jj];
    while (j >= 0 && (!eq(tab1, tab2, i, j + 1))) {
      j = p[j];
      while (j > -1 && changepat(tab1, i, j, -1) == 0) j = p[j];
    }
    changepat(tab1, i, j, -1);
    if (eq(tab1, tab2, i, j + 1)) j++, changepat(tab1, i, j, 0);
    p2[i] = j + 1;
    if (j + 1 == n2) {
      j = p[j];
      while (j > -1 && changepat(tab1, i, j, 0) == 0) j = p[j];
    }
    changepat(tab1, i, j, 0);
  }
}
char a[C], b[C];
int main() {
  int n, m, i, j, s = 0;
  scanf("%d %d", &n, &m);
  sget2(a);
  sget2(b);
  KM(b, m);
  FindStr(a, n, b, m, p, p2);
  for (i = 0; i < n; i++)
    if (p2[i] == m) s++;
  printf("%d\n", s);
  for (i = 0; i < n; i++)
    if (p2[i] == m) printf("%d ", i + 2 - m);
  return 0;
}
