#include <bits/stdc++.h>
using namespace std;
int N, M, K;
bool Matrix[105][105];
int ans = 11;
int Pattern[105];
void Read() {
  cin >> N >> M >> K;
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= M; j++) cin >> Matrix[i][j];
}
void Solve(int line) {
  int sum = 0;
  for (int i = 1; i <= N; i++) {
    int c0 = 0, c1 = 0;
    for (int j = 1; j <= M; j++)
      if (Matrix[line][j] != Matrix[i][j])
        ++c0;
      else
        ++c1;
    sum += min(c0, c1);
  }
  if (sum > K) return;
  ans = min(ans, sum);
}
void Solve2() {
  int sum = 0;
  for (int i = 1; i <= M; i++) {
    int c0 = 0, c1 = 0;
    for (int j = 1; j <= N; j++) {
      if (Matrix[j][i] != Pattern[j])
        ++c0;
      else
        ++c1;
    }
    sum += min(c0, c1);
  }
  if (sum > K) return;
  ans = min(ans, sum);
}
int main() {
  Read();
  if (N > K) {
    for (int i = 1; i <= N; i++) Solve(i);
    if (ans > K)
      cout << "-1\n";
    else
      cout << ans << "\n";
  } else {
    for (int conf = 0; conf < (1 << N); conf++) {
      for (int i = 0; i < N; i++)
        if ((conf & (1 << i)) == 0)
          Pattern[i + 1] = 0;
        else
          Pattern[i + 1] = 1;
      Solve2();
    }
    if (ans > K)
      cout << "-1\n";
    else
      cout << ans << "\n";
  }
  return 0;
}
