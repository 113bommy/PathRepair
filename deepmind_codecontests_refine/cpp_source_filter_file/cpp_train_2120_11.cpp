#include <bits/stdc++.h>
using namespace std;
void run() {
  char A[51][51];
  char B[51][51];
  int na, ma;
  cin >> na >> ma;
  for (int i = (0), ei = (na); i < ei; i++) scanf(" %s", A[i]);
  int nb, mb;
  cin >> nb >> mb;
  for (int i = (0), ei = (nb); i < ei; i++) scanf(" %s", B[i]);
  int best = -1, rx = -1, ry = -1;
  for (int x = (-51), ex = (52); x < ex; x++)
    for (int y = (-51), ey = (52); y < ey; y++) {
      int curr = 0;
      for (int i = (0), ei = (na); i < ei; i++)
        for (int j = (0), ej = (nb); j < ej; j++)
          if (i + x >= 0 && i + x < nb && j + y >= 0 && j + y < mb)
            curr += (A[i][j] - '0') * (B[i + x][j + y] - '0');
      if (curr > best) {
        best = curr;
        rx = x;
        ry = y;
      }
    }
  printf("%d %d\n", rx, ry);
}
int main() {
  run();
  return 0;
}
