#include <bits/stdc++.h>
using namespace std;
int G[100], N, SELECTED, LEN;
long long memo[51][51][51];
long long dp(int id, int GUESTS, int ACU, int SUM) {
  if (id == N) return ACU > SUM && GUESTS == 0;
  if (memo[id][GUESTS][ACU] != -1) return memo[id][GUESTS][ACU];
  long long w = 0;
  if (GUESTS > 0 && id != SELECTED && ACU + G[id] <= LEN)
    w += dp(id + 1, GUESTS - 1, ACU + G[id], SUM);
  w += dp(id + 1, GUESTS, ACU, SUM);
  return memo[id][GUESTS][ACU] = w;
}
double FACT[60];
int main() {
  FACT[0] = 1;
  for (int i = 1; i < 60; ++i) FACT[i] = FACT[i - 1] * i;
  cin >> N;
  int s = 0;
  for (int i = 0; i < N; ++i) {
    cin >> G[i];
    s += G[i];
  }
  cin >> LEN;
  if (s <= LEN) {
    cout << N << endl;
    return 0;
  }
  double ans = 0;
  for (int i = 0; i < N; ++i) {
    memset(memo, -1, sizeof(memo));
    for (int j = 0; j <= N - 1; ++j) {
      int bef = j, aft = N - 1 - j;
      SELECTED = i;
      long long w = dp(0, bef, 0, LEN - G[i]);
      ans += bef * w * FACT[bef] * FACT[aft];
    }
  }
  for (int i = 0; i < N; ++i) ans /= i + 1;
  printf("%0.10lf", ans);
}
