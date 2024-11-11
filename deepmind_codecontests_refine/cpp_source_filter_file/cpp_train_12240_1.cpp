#include <bits/stdc++.h>
using namespace std;
const int N = 10002;
int n, m, k;
int main(void) {
  scanf("%d%d%d", &n, &m, &k);
  k--;
  int cad_por_lane = 2 * m;
  int col = k / cad_por_lane;
  int d = (k - col * cad_por_lane) / 2;
  col++, d++;
  printf("%d %d ", col, d);
  if (d % 2 == 1)
    printf("L\n");
  else
    printf("R\n");
  return 0;
}
