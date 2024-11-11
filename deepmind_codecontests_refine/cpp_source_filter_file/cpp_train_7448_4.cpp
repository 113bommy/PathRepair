#include <bits/stdc++.h>
using namespace std;
const int INF = 0x7fffffff;
char a[200][200];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int main() {
  int n, m;
  char ch;
  while (scanf("%d %d %c", &n, &m, &ch) != EOF) {
    set<char> s;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) cin >> a[i][j];
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (a[i][j] == ch) {
          for (int k = 0; k < 4; ++k) {
            int x = i + dx[k];
            int y = j + dy[k];
            if (x < 0 || x >= n || y < 0 || y >= n) continue;
            if (a[x][y] != '.' && a[x][y] != ch) {
              s.insert(a[x][y]);
            }
          }
        }
      }
    }
    cout << s.size() << endl;
  }
  return 0;
}
