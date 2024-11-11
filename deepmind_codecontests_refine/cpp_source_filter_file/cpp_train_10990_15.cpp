#include <bits/stdc++.h>
using namespace std;
const int xx[] = {0, 1, 0, -1, -1, 1, -1, 1};
const int yy[] = {1, 0, -1, 0, 1, 1, -1, -1};
const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};
int month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int cen[10][302];
int main() {
  int i, j, k, n, d;
  scanf("%d%d", &n, &d);
  int x = d;
  k = 1;
  for (i = 1; k < month[n]; i++) {
    for (j = x; j <= 7 && k < month[n]; j++) cen[j][i] = k++;
    x = 1;
  }
  printf("%d\n", i - 1);
  return 0;
}
