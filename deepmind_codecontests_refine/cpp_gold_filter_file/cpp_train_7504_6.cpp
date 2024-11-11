#include <bits/stdc++.h>
using namespace std;
char sol[100010];
int ask(int r1, int c1, int r2, int c2) {
  printf("? %d %d %d %d\n", r1, c1, r2, c2);
  fflush(stdout);
  char sir[10];
  scanf("%s", sir);
  if (sir[0] == 'Y')
    return 1;
  else
    return 0;
}
int main() {
  int n;
  scanf("%d", &n);
  int nr = 0, pozx = n, pozy = n, poz = 2 * n - 2;
  while (nr < n - 1) {
    if (pozx - 1 > 0 && ask(1, 1, pozx - 1, pozy) == 1) {
      sol[poz] = 'D';
      poz--;
      pozx--;
    } else {
      sol[poz] = 'R';
      poz--;
      pozy--;
    }
    nr++;
  }
  nr = 0;
  poz = 0;
  pozx = 1;
  pozy = 1;
  while (nr < n - 1) {
    if (pozy + 1 <= n && ask(pozx, pozy + 1, n, n) == 1) {
      sol[++poz] = 'R';
      pozy++;
    } else {
      sol[++poz] = 'D';
      pozx++;
    }
    nr++;
  }
  printf("! ");
  for (int i = 1; i <= 2 * n - 2; i++) printf("%c", sol[i]);
  return 0;
}
