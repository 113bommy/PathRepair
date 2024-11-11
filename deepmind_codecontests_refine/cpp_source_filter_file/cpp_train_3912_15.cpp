#include <bits/stdc++.h>
using lint = long long int;
using pii = std::pair<int, int>;
using std::max;
using std::min;
using std::queue;
using std::vector;
int N;
int R[20], B[20];
char C[20];
int dp[100000][400];
bool check[100000];
int max_R, max_B;
queue<int> qu;
void recursion(int idx) {
  qu.push(idx);
  while (!qu.empty()) {
    int ind = qu.front();
    qu.pop();
    if (ind == (1 << N) - 1) {
      continue;
    }
    check[ind] = true;
    int cur = 1;
    int temp_R = 0, temp_B = 0;
    for (int i = 1; i <= N; i++) {
      if ((ind & cur) == cur) {
        if (C[i] == 'R') {
          temp_R++;
        } else {
          temp_B++;
        }
      }
      cur = cur << 1;
    }
    cur = 1;
    for (int i = 1; i <= N; i++) {
      if ((ind & cur) == 0) {
        for (int j = 0; j <= 260; j++) {
          if (dp[ind][j] != -1) {
            if (dp[ind + cur][j + max(R[i] - temp_R, 0)] == -1) {
              dp[ind + cur][j + max(R[i] - temp_R, 0)] =
                  dp[ind][j] + max(B[i] - temp_B, 0);
            } else {
              dp[ind + cur][j + max(R[i] - temp_R, 0)] =
                  min(dp[ind][j] + max(B[i] - temp_B, 0),
                      dp[ind + cur][j + max(R[i] - temp_R, 0)]);
            }
          }
        }
        if (!check[ind + cur]) {
          qu.push(ind + cur);
          check[ind + cur] = true;
        }
      }
      cur = cur << 1;
    }
  }
}
int main(void) {
  scanf("%d\n", &N);
  for (int i = 1; i <= N; i++) {
    scanf("%c %d %d\n", &C[i], &R[i], &B[i]);
    if (R[i] > 16) {
      max_R += R[i] - 16;
      R[i] = 16;
    }
    if (B[i] > 16) {
      max_B += B[i] - 16;
      B[i] = 16;
    }
  }
  for (int i = 0; i <= 70000; i++) {
    for (int j = 0; j <= 260; j++) {
      dp[i][j] = -1;
    }
  }
  dp[0][0] = 0;
  recursion(0);
  int ans = 2000000000;
  for (int i = 0; i < 400; i++) {
    if (dp[(1 << N) - 1][i] != -1) {
      ans = min(ans, max(i + max_R, dp[(1 << N) - 1][i] + max_B));
    }
  }
  printf("%d", ans + N);
  return 0;
}
