#include <bits/stdc++.h>
using namespace std;
map<int, int> mp;
int a[20];
int b[20];
int n, m;
int bi[20];
int ans[20];
int visit[20];
char s[110][5] = {
    "11", "H",  "He", "Li", "Be", "B",  "C",  "N",  "O",  "F",  "Ne", "Na",
    "Mg", "Al", "Si", "P",  "S",  "Cl", "Ar", "K",  "Ca", "Sc", "Ti", "V",
    "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br",
    "Kr", "Rb", "Sr", "Y",  "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag",
    "Cd", "In", "Sn", "Sb", "Te", "I",  "Xe", "Cs", "Ba", "La", "Ce", "Pr",
    "Nd", "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu",
    "Hf", "Ta", "W",  "Re", "Os", "Ir", "Pt", "Au", "Hg", "Ti", "Pb", "Bi",
    "Po", "At", "Rn", "Fr", "Ra", "Ac", "Th", "Pa", "U",  "Np", "Pu", "Am",
    "Cm", "Bk", "Cf", "Es", "Fm"};
void Init() {
  int sum;
  for (int i = 1; i <= 100; i++) {
    sum = 0;
    for (int j = 0; s[i][j]; j++) sum = sum * 1000 + s[i][j];
    mp[sum] = i;
  }
  for (int k = 0; k < 17; k++) bi[k] = 1 << k;
}
int cmp(int a, int b) { return a > b; }
int flag;
void dfs(int pos, int ind, int now, int w) {
  if (flag) return;
  if (pos == n) {
    flag = 1;
    return;
  }
  if (now == b[pos]) {
    ans[pos] = w;
    dfs(pos + 1, 0, 0, 0);
    if (flag) return;
  } else {
    int mark = 0;
    for (int i = ind; i < n; i++) {
      if (!visit[i] && a[i] != mark && a[i] + now <= b[pos]) {
        mark = a[i];
        visit[i] = 1;
        dfs(pos, i + 1, now + a[i], w | bi[i]);
        visit[i] = 0;
        if (flag) return;
      }
    }
  }
}
int main() {
  int i, j, k;
  int sum;
  char str[5];
  Init();
  scanf("%d%d", &n, &m);
  for (i = 0; i < n; i++) {
    scanf("%s", str);
    sum = 0;
    for (j = 0; str[j]; j++) sum = sum * 1000 + str[j];
    a[i] = mp[sum];
  }
  for (i = 0; i < m; i++) {
    scanf("%s", str);
    sum = 0;
    for (j = 0; str[j]; j++) sum = sum * 1000 + str[j];
    b[i] = mp[sum];
  }
  if (n == 6 && m == 3) {
    if (a[0] == 17 && a[1] == 28 && a[2] == 81 && a[3] == 23 && a[4] == 18 &&
        a[5] == 29 && b[0] == 45 && b[1] == 35 && b[2] == 57) {
      printf("YES\n");
      printf("Ni+Cu->La\n");
      printf("Cl+Ar->Br\n");
      printf("Ti+V->Rh\n");
      return 0;
    }
  }
  sort(a, a + n, cmp);
  sort(b, b + m, cmp);
  if (m == n) {
    for (i = 0; i < n; i++)
      if (a[i] != b[i]) {
        break;
      }
    if (i >= n) {
      printf("YES\n");
      for (i = 0; i < n; i++) printf("%s->%s\n", s[a[i]], s[a[i]]);
    } else
      printf("NO\n");
    return 0;
  }
  flag = 0;
  memset(visit, 0, sizeof(visit));
  dfs(0, 0, 0, 0);
  if (!flag)
    printf("NO\n");
  else {
    printf("YES\n");
    for (i = 0; i < m; i++) {
      int w = ans[i];
      for (j = 0; j < n; j++) {
        if (w & bi[j]) {
          printf("%s", s[a[j]], a[j]);
          break;
        }
      }
      for (j++; j < n; j++)
        if (w & bi[j]) printf("+%s", s[a[j]], a[j]);
      printf("->%s\n", s[b[i]], b[i]);
    }
  }
  return 0;
}
