#include <bits/stdc++.h>
using namespace std;
int F[42][1 << 20], M[42][26], N;
string T[45];
int f(int d, int m, int c, int p) {
  if (F[d][m] != 99999) return F[d][m];
  int ret = d < 2 * N - 2 ? -99999 : 0;
  for (int next_c = 0; next_c < 26; next_c++) {
    int next_m = M[d + 1][next_c] & (m | (2 * m));
    if (next_m > 0) ret = max(ret, -f(d + 1, next_m, next_c, 1 - p));
  }
  if (p == c) ret++;
  if ((p == 0 && c == 1) || (p == 1 && c == 0)) ret--;
  return F[d][m] = ret;
}
int main() {
  cin >> N;
  for (int i = 0; i < N; i++) cin >> T[i];
  for (int d = 0; d < 2 * N - 1; d++)
    for (int i = 0; i < N; i++)
      for (int c = 0; c < 26; c++) {
        int j = d - i;
        if (j >= 0 && j < N && T[i][j] - 'a' == c) M[d][c] |= (1 << i);
      }
  for (int d = 0; d < 42; d++)
    for (int m = 0; m < (1 << 20); m++) F[d][m] = 99999;
  if (f(0, 1, T[0][0] - 'a', 1) == 0)
    cout << "DRAW";
  else if (f(0, 1, T[0][0] - 'a', 1) > 0)
    cout << "SECOND";
  else
    cout << "FIRST";
}
