#include <bits/stdc++.h>
using namespace std;
const int Mod = 1e9 + 7;
const int Inf = 100;
const int N = 51;
int n, k, t[N][N][2], A = 0, B = 0, ans[N][N][2], c[N][N];
bool mark[N][N][2];
int go(int a, int b, int side) {
  if (t[a][b][side] != -1) return t[a][b][side];
  if (!a && !b) return t[a][b][side] = 0;
  t[a][b][side] = Inf;
  if (side == 0) {
    for (int i = 0; i <= a && 50 * i <= k; i++) {
      int x = min(b, (k - i * 50) / 100);
      if (i + x >= 2 || (b - x == 0 && a == 0) || (a - i == 0 && b == 0) ||
          (x == 1 && A - a))
        t[a][b][side] = min(t[a][b][side], go(a - i, b - x, 1 - side) + 1);
    }
  }
  if (side == 1) {
    if (A - a) t[a][b][side] = min(t[a][b][side], go(a + 1, b, 1 - side) + 1);
    if (B - b) t[a][b][side] = min(t[a][b][side], go(a, b + 1, 1 - side) + 1);
  }
  return t[a][b][side];
}
void pre() {
  for (int i = 0; i < N; i++) c[i][0] = 1;
  for (int i = 1; i < N; i++)
    for (int j = 1; j <= i; j++)
      c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % Mod;
}
int go2(int a, int b, int side) {
  if (ans[a][b][side] != -1) return ans[a][b][side];
  if (!a && !b) return ans[a][b][side] = 1;
  ans[a][b][side] = 0;
  int X = side ? A - a : a;
  int Y = side ? B - b : b;
  int sign = side ? 1 : -1;
  for (int i = 0; i <= X; i++)
    for (int j = 0; j <= Y; j++) {
      if ((i || j) && i * 50 + j * 100 <= k)
        if (go(a + sign * i, b + sign * j, 1 - side) == go(a, b, side) - 1) {
          int sum = 1LL * c[X][i] * c[Y][j] % Mod *
                    go2(a + sign * i, b + sign * j, 1 - side) % Mod;
          ans[a][b][side] = (ans[a][b][side] + sum) % Mod;
        }
    }
  return ans[a][b][side];
}
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    A += x == 50;
    B += x == 100;
  }
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) {
      t[i][j][0] = t[i][j][1] = -1;
      ans[i][j][0] = ans[i][j][1] = -1;
    }
  pre();
  if (go(A, B, 0) >= Inf) return cout << -1 << endl << 0 << endl, 0;
  cout << go(A, B, 0) << endl << go2(A, B, 0) << endl;
}
