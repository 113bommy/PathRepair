#include <bits/stdc++.h>
using namespace std;
const int TAM = 5e5 + 10;
char seq[TAM];
int n, t, last;
int nh, ns;
int nexth[TAM];
bool possible(int disp) {
  int tot = 0, pend = 0;
  int lft = nh, pospend = -1;
  for (int i = 0; i < n; i++) {
    if (lft == 0) break;
    tot++;
    if (seq[i] == 'H') {
      if (disp) {
        disp--;
        lft--;
        continue;
      }
      if (pospend == -1) pospend = i;
      pend++;
    } else if (seq[i] == 'S') {
      disp++;
      if (pospend == -1) continue;
      if (disp >= pend) {
        if (nexth[i] == -1) {
          tot += i - pospend;
          lft -= pend;
          pospend = -1;
        } else if (nexth[i] - i >= i - pospend) {
          tot += 2 * (i - pospend);
          pospend = -1;
          disp -= pend;
          lft -= pend;
          pend = 0;
        }
      }
    }
  }
  if (pospend != -1) tot += n - pospend - 1;
  if (tot > t) return false;
  return true;
}
int main() {
  last = -1;
  scanf("%d%d", &n, &t);
  scanf("%s", seq);
  nh = 0;
  ns = 0;
  int ph = -1;
  for (int i = n - 1; i >= 0; i--) {
    nexth[i] = ph;
    if (seq[i] == 'H') {
      last = max(last, i + 1);
      ph = i;
      nh++;
    }
    if (seq[i] == 'S') ns++;
  }
  if (last > t) {
    printf("-1\n");
    return 0;
  }
  int L = max(0, nh - ns);
  int R = nh - 1, mid;
  while (L <= R) {
    mid = (L + R) / 2;
    if (possible(mid))
      R = mid - 1;
    else
      L = mid + 1;
  }
  printf("%d\n", R + 1);
  return 0;
}
