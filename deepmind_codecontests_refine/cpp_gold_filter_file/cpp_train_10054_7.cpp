#include <bits/stdc++.h>
using namespace std;
const long long int OO = 3e14 + 20;
const int N = 1e5 + 20;
int arr[4][N], n;
long long int mem[4][N][2];
long long int solve(int x, int y, int ops) {
  if (y == n - 1) {
    if (x == 0 && ops)
      return max(0ll + arr[x][y] + arr[x + 1][y] + arr[x + 2][y],
                 0ll + arr[x][y] + arr[x + 1][y] + arr[x + 2][y] +
                     arr[x + 1][y - 1] + arr[x + 2][y - 1]);
    if (x == 0) return 0ll + arr[x][y] + arr[x + 1][y] + arr[x + 2][y];
    if (x == 1)
      return 0ll + arr[x + 1][y] + arr[x][y];
    else
      return 0ll + arr[x][y];
  }
  long long int &ret = mem[x][y][ops];
  if (~ret) return ret;
  ret = -OO;
  if (x == 0) {
    if (ops)
      ret = max(ret, solve(x + 2, y + 1, 0) + arr[x][y] + arr[x + 1][y] +
                         arr[x + 2][y] + arr[x + 1][y - 1] + arr[x + 2][y - 1]);
    ret = max(ret, solve(x, y + 1, 1) + arr[x][y]);
    ret = max(ret, solve(x + 1, y + 1, 0) + arr[x][y] + arr[x + 1][y]);
    ret = max(ret, solve(x + 2, y + 1, 0) + arr[x][y] + arr[x + 1][y] +
                       arr[x + 2][y]);
  }
  if (x == 1) {
    ret = max(ret, solve(x, y + 1, 0) + arr[x][y]);
    ret = max(ret, solve(x + 1, y + 1, 0) + arr[x][y] + arr[x + 1][y]);
    ret = max(ret, solve(x - 1, y + 1, 0) + arr[x][y] + arr[x - 1][y]);
  }
  if (x == 2) {
    if (ops)
      ret = max(ret, solve(x - 2, y + 1, 0) + arr[x][y] + arr[x - 1][y] +
                         arr[x - 2][y] + arr[x - 1][y - 1] + arr[x - 2][y - 1]);
    ret = max(ret, solve(x, y + 1, 1) + arr[x][y]);
    ret = max(ret, solve(x - 1, y + 1, 0) + arr[x][y] + arr[x - 1][y]);
    ret = max(ret, solve(x - 2, y + 1, 0) + arr[x][y] + arr[x - 1][y] +
                       arr[x - 2][y]);
  }
  return ret;
}
int main() {
  memset(mem, -1, sizeof mem);
  cin >> n;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < n; j++) cin >> arr[i][j];
  cout << solve(0, 0, 0) << '\n';
  return 0;
}
