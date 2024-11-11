#include <bits/stdc++.h>
#pragma warning(disable : 4996)
int tekmin, cycle, last;
int checked[1000];
int in[1000];
struct ans {
  int tank, tap, diam;
};
struct pair {
  int dest, dist;
};
int n;
int len[1000] = {0};
pair mas[1000][1000];
int comp(const void *a, const void *b) {
  return ((ans *)a)->tank - ((ans *)b)->tank;
}
void dfs(int ind) {
  int i;
  checked[ind] = 1;
  for (i = 0; i < len[ind]; i++) {
    if (checked[mas[ind][i].dest] == 0) {
      if (mas[ind][i].dist < tekmin) tekmin = mas[ind][i].dist;
      dfs(mas[ind][i].dest);
      if (last == -1) last = mas[ind][i].dest;
    } else
      cycle = 1;
  }
}
int main(void) {
  int p, t = 0, i, f, s, d;
  ans rez[1000];
  scanf("%d %d", &n, &p);
  if (n == 1 || p == 0) {
    printf("0");
    return 0;
  }
  for (i = 1; i <= n; i++) {
    checked[i] = 0;
    in[i] = 0;
    len[i] = 0;
  }
  for (i = 0; i < p; i++) {
    scanf("%d %d %d", &f, &s, &d);
    mas[f][len[f]].dest = s;
    mas[f][len[f]++].dist = d;
    in[s - 1] = 1;
  }
  for (i = 1; i <= n; i++) {
    if (in[i - 1] == 0 && len[i] > 0) {
      rez[t].tank = i;
      last = -1;
      tekmin = 999999;
      dfs(i);
      rez[t].tap = last;
      rez[t++].diam = tekmin;
    }
  }
  qsort(rez, t, sizeof(ans), comp);
  if (t == 0) {
    printf("0");
    return 0;
  }
  printf("%d\n", t);
  for (i = 0; i < t; i++)
    printf("%d %d %d\n", rez[i].tank, rez[i].tap, rez[i].diam);
  return 0;
}
