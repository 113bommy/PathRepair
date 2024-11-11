#include <bits/stdc++.h>
using namespace std;
vector<vector<char>> s;
void f(int x, int y) {
  if (x < 0 || y < 0) return;
  int q = 0;
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) q += s[x + i][y + j] == '*' ? 1 : 0;
  }
  if (q != 1) return;
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) s[x + i][y + j] = '.';
  }
  for (int i = -1; i < 2; ++i) {
    for (int j = -1; j < 2; ++j) f(x + i, y + j);
  }
}
int main() {
  int n, m;
  string k;
  cin >> n >> m;
  s.resize(n + 2, vector<char>(m + 2, '*'));
  for (int i = 0; i < n; ++i) {
    cin >> k;
    for (int j = 0; j < m; ++j) s[i][j] = k[j];
  }
  for (int i = 1; i < n; ++i)
    for (int j = 1; j < m; ++j) f(i, j);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) cout << s[i][j];
    cout << '\n';
  }
  return 0;
}
