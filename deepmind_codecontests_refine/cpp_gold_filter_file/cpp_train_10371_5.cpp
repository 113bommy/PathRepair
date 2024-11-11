#include <bits/stdc++.h>
using namespace std;
double p[150][150], win[150][150], score[150][150];
int n;
void dfs(int ind, int l, int r) {
  if (l == r) {
    win[ind][l] = 1;
    score[ind][l] = 0;
    return;
  }
  int mid = (l + r) / 2;
  dfs(2 * ind, l, mid);
  dfs(2 * ind + 1, mid + 1, r);
  for (int i = l; i <= mid; i++) {
    for (int j = mid + 1; j <= r; j++) {
      win[ind][i] += win[2 * ind][i] * win[2 * ind + 1][j] * p[i][j];
    }
  }
  for (int i = l; i <= mid; i++) {
    for (int j = mid + 1; j <= r; j++) {
      score[ind][i] = max(score[ind][i], score[2 * ind][i] +
                                             win[ind][i] * ((r - l + 1) / 2) +
                                             score[2 * ind + 1][j]);
    }
  }
  for (int i = mid + 1; i <= r; i++) {
    for (int j = l; j <= mid; j++) {
      win[ind][i] += win[2 * ind + 1][i] * win[2 * ind][j] * p[i][j];
    }
  }
  for (int i = mid + 1; i <= r; i++) {
    for (int j = l; j <= mid; j++) {
      score[ind][i] = max(score[ind][i], score[2 * ind + 1][i] +
                                             win[ind][i] * ((r - l + 1) / 2) +
                                             score[2 * ind][j]);
    }
  }
}
int main() {
  scanf("%d", &n);
  int num = (1 << n);
  for (int i = 1; i <= num; i++) {
    for (int j = 1; j <= num; j++) {
      double temp;
      scanf("%lf", &temp);
      p[i][j] = 0.01 * temp;
    }
  }
  dfs(1, 1, num);
  double MAX = 0;
  for (int i = 1; i < 150 - 1; i++) {
    MAX = max(MAX, score[1][i]);
  }
  printf("%0.9lf\n", MAX);
  return 0;
}
