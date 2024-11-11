#include <bits/stdc++.h>
using namespace std;
int n;
char sol[172][172];
void baga(int i, int j) { sol[i][j] = sol[j][i] = 'Y'; }
int main() {
  scanf("%d", &n);
  if (n == 1) {
    printf("2\nNY\nYN\n");
    return 0;
  }
  int cn = n, nr = 0, i, j;
  for (i = 1; i <= 170; i++)
    for (j = 1; j <= 170; j++) sol[i][j] = 'N';
  while (cn != 1) {
    nr++;
    cn /= 2;
  }
  int last = 1, u, cu;
  for (i = 1; i <= nr; i++) {
    baga(last, 3 * i);
    baga(last, 3 * i + 1);
    baga(3 * i, 3 * i + 2);
    baga(3 * i + 1, 3 * i + 2);
    last = 3 * i + 2;
  }
  cu = last;
  if (last == 1) last++;
  baga(last - 1, 2);
  baga(last - 2, 2);
  if (last == 2) last--;
  last = 1;
  for (i = 1; i <= nr; i++) {
    baga(last, 100 + 2 * i);
    last = 100 + 2 * i;
    baga(last, last + 1);
    last++;
  }
  last--;
  u = 2;
  while (n != 1) {
    if (n & 1) {
      baga(last, u);
    }
    cu -= 3;
    u = cu;
    last -= 2;
    n /= 2;
  }
  printf("170\n");
  for (i = 1; i <= 170; i++) {
    for (j = 1; j <= 170; j++) printf("%c", sol[i][j]);
    printf("\n");
  }
  return 0;
}
