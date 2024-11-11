#include <bits/stdc++.h>
using namespace std;
double dp[200];
int next1[200];
int cnt(int i, int j) {
  if ((11 - i) % 2 == 0) {
    return (10 - i) * 10 + j;
  } else {
    return (10 - i) * 10 + (11 - j);
  }
}
int main() {
  for (int i = (1); i < (11); i++) {
    for (int j = (1); j < (11); j++) {
      int x;
      cin >> x;
      int now = cnt(i, j);
      int net = cnt(i - x, j);
      next1[now] = net;
    }
  }
  for (int i = (0); i < (6); i++) dp[99 - i] = 6;
  for (int i = 93; i >= 1; i--) {
    dp[i] = 1;
    for (int j = (1); j < (7); j++) {
      dp[i] += min(dp[i + j], dp[next1[i + j]]) / 6;
    }
  }
  printf("%.10lf", dp[1]);
  return 0;
}
