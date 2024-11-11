#include <bits/stdc++.h>
using namespace std;
int n, v[2][5], cor[5], cop[5], score[] = {500, 1000, 1500, 2000, 2500, 3000};
double perc[][2] = {{1, .5},       {.5, .25},       {.25, .125},
                    {.125, .0625}, {.0625, .03125}, {.03125, 0}};
int fix(int mid, int u) {
  if (v[1][u] + v[0][u] == -2) return 0;
  if (v[1][u] == -1 || v[0][u] < v[1][u]) return 0;
  return mid;
}
int find(int u, int mid) {
  double x = (double)cop[u] / (n + mid);
  for (int i = 0; i < 6; i++)
    if ((perc[i][0] >= x || fabs(x - perc[i][0]) <= 1e-9) &&
        (perc[i][1] < x || (i == 5 && fabs(perc[i][1] - x) <= 1e-9)))
      return score[i];
}
bool check(int mid) {
  for (int i = 0; i < 5; i++) cop[i] = cor[i] + fix(mid, i);
  int sum = 0, sum1 = 0;
  for (int i = 0; i < 5; i++) {
    int k = find(i, mid);
    if (v[0][i] != -1) sum += k - k * v[0][i] / 250;
    if (v[1][i] != -1) sum1 += k - k * v[1][i] / 250;
  }
  return sum > sum1;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 5; j++) {
      int a;
      scanf("%d", &a);
      if (i < 2) v[i][j] = a;
      if (a > -1) cor[j]++;
    }
  }
  for (int i = 0; i <= 1e6; i++)
    if (check(i)) return printf("%d\n", i), 0;
  puts("-1");
}
