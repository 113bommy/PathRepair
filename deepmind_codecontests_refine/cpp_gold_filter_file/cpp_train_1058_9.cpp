#include <bits/stdc++.h>
using namespace std;
int n, s[50][50][50][50];
int f(int a, int b, int x, int y) {
  int &temp = s[a][b][x][y];
  if (temp != -1) return temp;
  temp = max(x - a, y - b) + 1;
  for (int i = a; i < x; i++)
    temp = min(temp, f(a, b, i, y) + f(i + 1, b, x, y));
  for (int i = b; i < y; i++)
    temp = min(temp, f(a, b, x, i) + f(a, i + 1, x, y));
  return temp;
}
int main() {
  memset(s, -1, sizeof s);
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      char temp;
      cin >> temp;
      if (temp == '#')
        s[i][j][i][j] = 1;
      else
        s[i][j][i][j] = 0;
    }
  }
  cout << f(0, 0, n - 1, n - 1) << '\n';
}
