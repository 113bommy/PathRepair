#include <bits/stdc++.h>
using namespace std;
const int Max = 510;
int n, m, a, b, x, y;
bool vis[Max + 5][Max + 5], flag = false;
void input();
bool check(int i, int j) {
  if (i < 0 || j < 0 || i == n || j == m || (vis[i][j] && flag))
    return false;
  else
    return true;
}
bool Fill(int i, int j) {
  if (i == x && j == y && vis[i][j] && flag) return true;
  if (!check(i, j)) return false;
  flag = true;
  vis[i][j] = true;
  return (Fill(i, j - 1) || Fill(i, j + 1) || Fill(i + 1, j) || Fill(i - 1, j));
}
int main() {
  (ios_base::sync_with_stdio(false), cin.tie(NULL));
  ;
  int i, j;
  flag = false;
  input();
  if (Fill(a, b))
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
void input() {
  char ch;
  int i, j;
  cin >> n >> m;
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; ++j) {
      cin >> ch;
      if (ch == 'X') vis[i][j] = true;
    }
  }
  cin >> a >> b >> x >> y;
  a--;
  b--, x--, y--;
}
