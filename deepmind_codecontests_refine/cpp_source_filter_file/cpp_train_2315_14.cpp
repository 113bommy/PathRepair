#include <bits/stdc++.h>
using namespace std;
int dp[1000000 + 5];
int to[1000000 + 5];
int one[1000000 + 5];
int zero[1000000 + 5];
char S[1000000 + 5];
int N;
int cost(int i, int j) {
  return min(one[i] - one[j + 1], 2 + zero[i] - zero[j + 1]);
}
void func(int i, int j) {
  if (cost(i, j) == 0) return;
  int x = one[i] - one[j + 1];
  int y = 2 + zero[i] - zero[j + 1];
  if (x < y) {
    for (int k = i; k <= j; ++k) {
      if (S[k - 1] == '1') {
        printf("+2^%d\n", N - k);
      }
    }
  } else {
    printf("+2^%d\n", N - i + 1);
    printf("-2^%d\n", N - j);
    for (int k = i; k <= j; ++k) {
      if (S[k - 1] == '0') {
        printf("-2^%d\n", N - k);
      }
    }
  }
}
int main() {
  scanf(" %s", &S);
  N = strlen(S);
  for (int i = N; i >= 1; i--) {
    one[i] = one[i + 1] + (S[i - 1] == '1');
    zero[i] = zero[i + 1] + (S[i - 1] == '0');
  }
  int mn1 = 0;
  int mn0 = 0;
  int pmn1 = N + 1;
  int pmn0 = N + 1;
  for (int i = N; i >= 1; i--) {
    dp[i] = cost(i, i) + dp[i + 1];
    to[i] = i;
    if (dp[i] > one[i] + mn1) {
      dp[i] = one[i] + mn1;
      to[i] = pmn1;
    }
    if (dp[i] > 2 + zero[i] + mn0) {
      dp[i] = 2 + zero[i] + mn0;
      to[i] = pmn0;
    }
    if (mn1 > dp[i] - one[i]) {
      mn1 = dp[i] - one[i];
      pmn1 = i - 1;
    }
    if (mn0 > dp[i] - zero[i]) {
      mn0 = dp[i] - zero[i];
      pmn0 = i - 1;
    }
  }
  printf("%d\n", dp[1]);
  int at = 1;
  while (at <= N) {
    int till = to[at];
    func(at, till);
    at = till + 1;
  }
}
