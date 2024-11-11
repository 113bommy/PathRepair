#include <bits/stdc++.h>
double win_prob[6][64], cumu_prob[6][64], dp[6][64][64];
int N, p[64][64], player;
double expectScore(int round, int start, int end) {
  if (dp[round - 1][start][end] != -1) {
    return dp[round - 1][start][end];
  } else if (round == 1) {
    dp[0][start][end] = win_prob[0][start] > win_prob[0][end]
                            ? win_prob[0][start]
                            : win_prob[0][end];
    return dp[0][start][end];
  } else if (round > 0) {
    double high = 0.000, score;
    int arr[64];
    for (int i = start; i <= end; i++) {
      score = cumu_prob[round - 1][i];
      for (int j = start; j <= end; j++) {
        arr[j] = -1;
        for (int k = 0; k < round; k++) {
          if (i / (1 << k) != j / (1 << k)) arr[j] = k;
        }
      }
      int left, right;
      for (int k = 1; k < round; k++) {
        left = 0;
        for (int j = start; j <= end; j++) {
          if (arr[j] == k && left == 0) left = j;
          if (arr[j] == k) right = j;
        }
        score += expectScore(k, left, right);
      }
      if (high < score) high = score;
    }
    dp[round - 1][start][end] = high;
    return dp[round - 1][start][end];
  }
}
int main() {
  scanf("%d", &N);
  player = 1 << N;
  for (int i = 0; i < player; i++)
    for (int j = 0; j < player; j++) scanf("%d", &p[i][j]);
  for (int i = 0; i < player; i += 2) {
    win_prob[0][i] = p[i][i + 1] / 100.0;
    win_prob[0][i + 1] = p[i + 1][i] / 100.0;
  }
  for (int i = 1; i < N; i++) {
    for (int j = 0; j < player; j++) {
      win_prob[i][j] = 0.00;
      for (int k = 0; k < player; k++)
        if (j / (1 << i) != k / (1 << i) &&
            j / (1 << (i + 1)) == k / (1 << (i + 1)))
          win_prob[i][j] += p[j][k] * win_prob[i - 1][k] / 100.0;
      win_prob[i][j] *= win_prob[i - 1][j];
    }
  }
  for (int j = 0; j < player; j++) {
    for (int i = 0; i < N; i++) win_prob[i][j] *= (1 << i);
    cumu_prob[0][j] = win_prob[0][j];
    for (int i = 1; i < N; i++)
      cumu_prob[i][j] = cumu_prob[i - 1][j] + win_prob[i][j];
  }
  for (int i = 0; i < N; i++)
    for (int j = 0; j < player; j++)
      for (int k = 0; k < player; k++) dp[i][j][k] = -1.000;
  printf("%.12lf\n", expectScore(N, 0, player - 1));
  return 0;
}
