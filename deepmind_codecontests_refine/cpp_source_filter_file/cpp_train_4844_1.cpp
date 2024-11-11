#include <bits/stdc++.h>
using namespace std;
const int nmax = 200001;
int a[nmax], b[nmax];
int n, i, posa, posb;
bool ok = true;
int main() {
  scanf("%d", &n);
  for (i = 0; i < n; i++) scanf("%d", &a[i]);
  for (i = 0; i < n; i++) scanf("%d", &b[i]);
  posb = 0;
  if (b[posb] == 0) posb++;
  for (i = 0; i < n; i++)
    if (a[i] == b[posb]) {
      posa = i;
      break;
    }
  for (i = 0; i < n; i++) {
    if (b[posb] == 0) posb++;
    if (posa == n) posa = 0;
    if (a[posa] == 0) {
      posa++;
      if (posa == n) posa = 0;
    }
    if (a[posa] != b[posb]) {
      ok = false;
      break;
    }
    posa++;
    posb++;
  }
  if (ok)
    printf("YES\n");
  else
    printf("NO\n");
}
