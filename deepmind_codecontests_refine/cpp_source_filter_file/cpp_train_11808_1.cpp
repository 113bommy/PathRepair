#include <bits/stdc++.h>
int prab[5000];
int n, m;
int hun[5000], zero[5000];
int went[3010][3010];
int sm[10000000], ne[10000000];
int head, tail;
int resu;
void bfs() {
  resu = 1;
  if (n == 1) return;
  head = tail = 1;
  sm[tail] = 1;
  ne[tail] = 2;
  tail++;
  went[1][2] = 1;
  while (head < tail) {
    int cnts = sm[head], cntn = ne[head];
    head++;
    if (!hun[cntn] && prab[cnts] != 0) {
      int ns = cnts, nn = cntn + 1;
      if (ns > n) ns = n + 1;
      if (nn > n) nn = n + 1;
      if (!went[ns][nn]) {
        went[ns][nn] = went[cnts][cntn] + 1;
        resu++;
        if (ns <= n && nn <= n && went[ns][nn] < m) {
          sm[tail] = ns;
          ne[tail] = nn;
          tail++;
        }
      }
    }
    if (!zero[cntn] && prab[cnts] != 100) {
      int ns = cntn, nn = cntn + 1;
      if (ns > n) ns = n + 1;
      if (nn > n) nn = n + 1;
      if (!went[ns][nn]) {
        went[ns][nn] = went[cnts][cntn] + 1;
        resu++;
        if (ns <= n && nn <= n && went[ns][nn] < m) {
          sm[tail] = ns;
          ne[tail] = nn;
          tail++;
        }
      }
    }
    if (!zero[cntn] && prab[cnts] != 0) {
      int ns = cntn + 1, nn = cntn + 2;
      if (ns > n) ns = n + 1;
      if (nn > n) nn = n + 1;
      if (!went[ns][nn]) {
        went[ns][nn] = went[cnts][cntn] + 1;
        resu++;
        if (ns <= n && nn <= n && went[ns][nn] < m) {
          sm[tail] = ns;
          ne[tail] = nn;
          tail++;
        }
      }
    }
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &prab[i]);
  zero[n + 1] = 1;
  for (int i = n; i; i--) {
    hun[i] = (hun[i + 1] || (prab[i] == 100));
    zero[i] = (zero[i + 1] && (prab[i] == 0));
  }
  bfs();
  printf("%d\n", resu);
  return 0;
}
