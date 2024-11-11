#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 4;
const long long mod = 1e9 + 7;
const int INF = 1e9 + 4;
const double eps = 1e-7;
int a[N], b[N];
string s;
int n, m, t;
char gra[55][55];
int dx[] = {0, 0, 1, 0, -1};
int dy[] = {0, 1, 0, -1, 0};
bool ingra(int x, int y) { return x >= 1 && y >= 1 && x <= n && y <= n; }
bool Tia(int x, int y) {
  x++;
  for (int i = 0; i < 5; ++i) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (!ingra(nx, ny)) return false;
    if (gra[nx][ny] == '#') return false;
    gra[nx][ny] = '#';
  }
  return true;
}
void Pri() {
  for (int i = 1; i <= n; ++i) printf("%s\n", gra[i] + 1);
  cout << endl;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    scanf("%s", gra[i] + 1);
  }
  bool f = true;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (gra[i][j] == '.') {
        f = f & Tia(i, j);
        if (f == false) break;
      }
    }
  }
  if (f)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
