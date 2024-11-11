#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int INF = INT_MAX;
const long long LINF = LLONG_MAX;
const int maxn = 2e3 + 10;
char a[maxn][maxn], U = '^', D = 'v', L = '<', R = '>';
bool visited[maxn][maxn];
queue<pair<int, int> > q;
int n, m;
int deg(int x, int y) {
  int res = 0;
  res += (a[x - 1][y] == '.');
  res += (a[x + 1][y] == '.');
  res += (a[x][y + 1] == '.');
  res += (a[x][y - 1] == '.');
  return res;
}
void print() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) cout << a[i][j];
    cout << endl;
  }
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> a[i][j];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      int d = deg(i, j);
      if (a[i][j] == '.') {
        if (d == 0) return cout << "Not unique" << endl, 0;
        if (d == 1) {
          visited[i][j] = 1;
          q.push({i, j});
        }
      }
    }
  while (!q.empty()) {
    pair<int, int> v = q.front();
    int x = v.first, y = v.second;
    vector<pair<int, int> > p = {{x + 1, y - 1}, {x + 1, y + 1}, {x + 2, y},
                                 {x - 1, y - 1}, {x - 1, y + 1}, {x - 2, y},
                                 {x, y + 2},     {x, y - 2}};
    if (a[x + 1][y] == '.') {
      a[x][y] = U;
      a[x + 1][y] = D;
    }
    if (a[x - 1][y] == '.') {
      a[x][y] = D;
      a[x - 1][y] = U;
    }
    if (a[x][y + 1] == '.') {
      a[x][y] = L;
      a[x][y + 1] = R;
    }
    if (a[x][y - 1] == '.') {
      a[x][y] = R;
      a[x][y - 1] = L;
    }
    for (auto i : p)
      if (!visited[i.first][i.second] && deg(i.first, i.second) == 1 &&
          a[i.first][i.second] == '.') {
        visited[i.first][i.second] = 1;
        q.push(i);
      }
    q.pop();
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (a[i][j] == '.') return cout << "Not unique" << endl, 0;
  print();
}
