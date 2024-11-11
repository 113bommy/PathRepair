#include <bits/stdc++.h>
using namespace std;
bool _isPrime(int n) {
  if (n == 2) return true;
  if (n < 2 || n % 2 == 0) return false;
  for (int i = 3; i * i <= n; i += 2)
    if (n % i == 0) return false;
  return true;
}
int row, col;
int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};
struct Point {
  int x;
  int y;
};
bool _Asc_compare(Point lhs, Point rhs) { return lhs.x < rhs.x; }
bool _Desc_compare(Point lhs, Point rhs) { return lhs.x > rhs.x; }
int _unique(int x, int y) { return (x + (y * 100000)); }
string s, t;
char ch, dh;
char crr[101][101];
int a, b, c, d, e, n, x, y, z;
vector<string> A(55);
vector<int> V[100010];
int clr[100][100], par[100010], ans = 0, cat = 0;
void dfs(int x, int y, int fxx, int fyy, char c) {
  if (x < 0 || x >= row || y < 0 || y >= col) return;
  if (A[x][y] != c) return;
  if (clr[x][y]) {
    ans = 1;
    return;
  }
  clr[x][y] = 1;
  for (int i = 0; i < 4; i++) {
    int n1, n2;
    n1 = x + fx[i];
    n2 = y + fy[i];
    if (n1 == fxx && n2 == fyy) continue;
    dfs(n1, n2, x, y, c);
  }
}
int main() {
  cin >> row >> col;
  for (int i = 0; i < row; i++) cin >> A[i];
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      if (!clr[i][j]) {
        dfs(i, j, -1, -1, A[i][j]);
      }
    }
  }
  if (ans)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
