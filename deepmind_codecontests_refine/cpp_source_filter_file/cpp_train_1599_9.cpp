#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int sum(int a, int b) {
  a = (a % MOD) + (b % MOD);
  return a;
}
int sum(int a, int b, int c) {
  a = a % MOD;
  a = a + (b % MOD);
  a = a % MOD;
  a = a + (c % MOD);
  a = a % MOD;
  return a;
}
int main() {
  int N;
  scanf("%d", &N);
  int DP[N + 1][2];
  DP[0][0] = DP[0][1] = 0;
  DP[1][0] = 0;
  DP[1][1] = 1;
  for (int i = 2; i <= N; i++) {
    if (i % 2 == 0) {
      DP[i][1] = DP[i - 1][1];
      DP[i][0] = sum(DP[i - 1][0], DP[i - 1][1], 1);
    } else {
      DP[i][1] = sum(DP[i - 1][1], DP[i - 1][0], 1);
      DP[i][0] = DP[i - 1][0];
    }
  }
  cout << sum(DP[N][0], DP[N][1]) << endl;
  return 0;
}
