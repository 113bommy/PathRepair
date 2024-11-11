#include <bits/stdc++.h>
using namespace std;
int N;
int X[6060], Y[6060];
long long C[4][4];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin.exceptions(ios::badbit | ios::failbit);
  cin >> N;
  for (int i = 1; i <= N; i++) cin >> X[i] >> Y[i];
  long long res = 0;
  for (int i = 1; i <= N; i++) C[X[i] % 4][Y[i] % 4]++;
  res += C[0][0] * (C[0][0] - 1) * (C[0][0] - 2) / 6;
  res += C[0][2] * (C[0][2] - 1) * (C[0][2] - 2) / 6;
  res += C[2][0] * (C[2][0] - 1) * (C[2][0] - 2) / 6;
  res += C[2][2] * (C[2][2] - 1) * (C[2][2] - 2) / 6;
  for (int i = 1; i <= N; i++)
    for (int j = i + 1; j <= N; j++) {
      if (X[i] % 4 == X[j] % 4 && Y[i] % 4 == Y[j] % 4) {
        int x = X[i] % 4, y = Y[i] % 4;
        for (int nx = 0; nx < 4; nx += 2)
          for (int ny = 0; ny < 4; ny += 2) {
            if (nx == x && ny == y) continue;
            res += C[nx][ny];
          }
      }
    }
  cout << res << "\n";
  return 0;
}
