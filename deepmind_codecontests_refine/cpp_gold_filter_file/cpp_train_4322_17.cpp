#include <bits/stdc++.h>
using namespace std;
double dp[2100][2100][2][2];
int n, h;
double p;
int Coordinate_X[2100];
int Influence[2100][2];
void Initalize() {
  for (int i = 0; i <= 2010; i++)
    for (int j = 0; j <= 2010; j++)
      for (int k = 0; k <= 1; k++)
        for (int l = 0; l <= 1; l++) dp[i][j][k][l] = -1;
}
void Initalization_of_Influence() {
  for (int i = 2; i <= n - 1; i++) {
    if (Coordinate_X[i] - Coordinate_X[i - 1] < h)
      Influence[i][0] = Influence[i - 1][0] + 1;
    else
      Influence[i][0] = 1;
  }
  for (int i = n - 1; i >= 2; i--) {
    if (Coordinate_X[i + 1] - Coordinate_X[i] < h)
      Influence[i][1] = Influence[i + 1][1] + 1;
    else
      Influence[i][1] = 1;
  }
}
double Dynamic_Programming(int li, int ri, int col1, int col2) {
  if (li > ri) return 0;
  if (dp[li][ri][col1][col2] != -1) return dp[li][ri][col1][col2];
  double ret = 0;
  if (col1 == 1)
    ret += p * (min(h, Coordinate_X[li] - Coordinate_X[li - 1] - h) +
                Dynamic_Programming(li + 1, ri, 0, col2));
  else
    ret += p * (min(h, Coordinate_X[li] - Coordinate_X[li - 1]) +
                Dynamic_Programming(li + 1, ri, 0, col2));
  int new_ri = min(ri, li + Influence[li][1] - 1);
  if (new_ri == ri) {
    if (col2 == 0)
      ret += (1 - p) * (min(h, Coordinate_X[ri + 1] - Coordinate_X[ri] - h) +
                        Coordinate_X[ri] - Coordinate_X[li]);
    else
      ret += (1 - p) * (min(h, Coordinate_X[ri + 1] - Coordinate_X[ri]) +
                        Coordinate_X[ri] - Coordinate_X[li]);
  } else {
    ret += (1 - p) * (h + Coordinate_X[new_ri] - Coordinate_X[li] +
                      Dynamic_Programming(new_ri + 1, ri, 1, col2));
  }
  if (col2 == 0)
    ret += (1 - p) * (min(h, Coordinate_X[ri + 1] - Coordinate_X[ri] - h) +
                      Dynamic_Programming(li, ri - 1, col1, 1));
  else
    ret += (1 - p) * (min(h, Coordinate_X[ri + 1] - Coordinate_X[ri]) +
                      Dynamic_Programming(li, ri - 1, col1, 1));
  int new_li = max(li, ri - Influence[ri][0] + 1);
  if (new_li == li) {
    if (col1 == 1)
      ret += p * (min(h, Coordinate_X[li] - Coordinate_X[li - 1] - h) +
                  Coordinate_X[ri] - Coordinate_X[li]);
    else
      ret += p * (min(h, Coordinate_X[li] - Coordinate_X[li - 1]) +
                  Coordinate_X[ri] - Coordinate_X[li]);
  } else {
    ret += p * (h + Coordinate_X[ri] - Coordinate_X[new_li] +
                Dynamic_Programming(li, new_li - 1, col1, 0));
  }
  ret /= 2.0;
  dp[li][ri][col1][col2] = ret;
  return ret;
}
int main() {
  Initalize();
  scanf("%d%d%lf", &n, &h, &p);
  for (int i = 1; i <= n; i++) scanf("%d", &Coordinate_X[i]);
  Coordinate_X[++n] = -0x3f3f3f3f, Coordinate_X[++n] = 0x3f3f3f3f;
  sort(Coordinate_X + 1, Coordinate_X + n + 1);
  Initalization_of_Influence();
  printf("%.6lf\n", Dynamic_Programming(2, n - 1, 0, 1));
}
