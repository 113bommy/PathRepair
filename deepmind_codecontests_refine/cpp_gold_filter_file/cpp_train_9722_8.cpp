#include <bits/stdc++.h>
const int MAXN = 1e5 + 1;
const int INF = 1e9 + 7;
using namespace std;
int f[MAXN][10][10][2][2];
string A, B;
void add(int &a, int b) {
  a += b;
  if (a >= INF) a -= INF;
}
int n;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  cin >> A >> B;
  A = '=' + A;
  B = '=' + B;
  f[0][0][0][0][0] = 1;
  for (int i = 0; i < n; i++)
    for (int x = 0; x <= 9; x++)
      for (int y = 0; y <= 9; y++)
        for (int p = 0; p <= 1; p++)
          for (int q = 0; q <= 1; q++)
            if (f[i][x][y][p][q]) {
              int d1 = 0, c1 = 9, d2 = 0, c2 = 9;
              if (A[i + 1] != '?') d1 = A[i + 1] - '0', c1 = d1;
              if (B[i + 1] != '?') d2 = B[i + 1] - '0', c2 = d2;
              for (int x1 = d1; x1 <= c1; x1++)
                for (int y1 = d2; y1 <= c2; y1++)
                  add(f[i + 1][x1][y1][p | (x1 < y1)][q | (x1 > y1)],
                      f[i][x][y][p][q]);
            }
  int ans = 0;
  for (int x = 0; x <= 9; x++)
    for (int y = 0; y <= 9; y++) add(ans, f[n][x][y][1][1]);
  cout << ans;
  return 0;
}
