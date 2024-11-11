#include <bits/stdc++.h>
using namespace std;
char bra[1000009], inst[1000009];
int lnext[1000009], rnext[1000009];
int h[1000009];
int cmp[1000009];
int main() {
  int n, m, p, i, j;
  for (i = 0; i <= 1000007; i++) rnext[i] = i + 1;
  for (i = 1000007; i >= 1; i--) lnext[i] = i - 1;
  scanf("%d%d%d", &n, &m, &p);
  p--;
  scanf("%s", bra);
  scanf("%s", inst);
  int c = 0;
  for (i = 0; i < n; i++) {
    if (bra[i] == '(') {
      c++;
      h[c] = i;
    } else {
      cmp[i] = h[c];
      cmp[h[c]] = i;
      c--;
    }
  }
  for (i = 0; i <= 1000007; i++) h[i] = 0;
  int rg = n - 1;
  for (i = 0; i < m; i++) {
    if (inst[i] == 'L')
      p = lnext[p];
    else if (inst[i] == 'R')
      p = rnext[p];
    else {
      if (bra[p] == '(') {
        h[p] += 1;
        h[rnext[cmp[p]]] -= 1;
        rnext[lnext[p]] = rnext[cmp[p]];
        lnext[rnext[cmp[p]]] = lnext[p];
        if (rnext[cmp[p]] <= rg)
          p = rnext[cmp[p]];
        else {
          p = lnext[p];
          rg = lnext[p];
        }
      } else {
        h[cmp[p]] += 1;
        h[rnext[p]] -= 1;
        rnext[lnext[cmp[p]]] = rnext[p];
        lnext[rnext[p]] = lnext[cmp[p]];
        if (rnext[p] <= rg)
          p = rnext[p];
        else {
          p = lnext[cmp[p]];
          rg = lnext[cmp[p]];
        }
      }
    }
  }
  int sum = 0;
  for (i = 0; i < n; i++) {
    sum += h[i];
    if (sum == 0) printf("%c", bra[i]);
  }
  printf("\n");
  return 0;
}
