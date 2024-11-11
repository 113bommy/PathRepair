#include <bits/stdc++.h>
using namespace std;
char A[52][52];
bool res = false;
char dif = 'a' - 'A';
int d;
void f(char c, int x, int y) {
  if (A[x][y] != c) return;
  A[x][y] += dif;
  if (d != 1 && A[x - 1][y] == c + dif) {
    res = true;
    return;
  }
  if (d != 2 && A[x + 1][y] == c + dif) {
    res = true;
    return;
  }
  if (d != 3 && A[x][y - 1] == c + dif) {
    res = true;
    return;
  }
  if (d != 4 && A[x][y + 1] == c + dif) {
    res = true;
    return;
  }
  d = 1;
  f(c, x + 1, y);
  d = 2;
  f(c, x - 1, y);
  d = 3;
  f(c, x, y + 1);
  d = 4;
  f(c, x, y - 1);
}
int main() {
  ios_base::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> A[i] + 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (A[i][j] < 'a') f(A[i][j], i, j);
    }
  }
  cout << (res ? "YES" : "NO") << endl;
  return 0;
}
