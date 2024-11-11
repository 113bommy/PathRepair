#include <bits/stdc++.h>
using namespace std;
const int N = 555;
int n, a[N][N], x0, y234324, used[N][N];
int m = 0;
char ans[3000001];
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const char code[] = {'R', 'D', 'L', 'U'};
const char rcode[] = {'L', 'U', 'R', 'D'};
inline bool good(int first) { return 0 <= first && first < n; }
inline void add(char c) { ans[m++] = c; }
void dfs(int first, int second) {
  used[first][second] = true;
  if (a[first][second] == 0) {
    add('1');
    a[first][second] = 1;
  }
  for (int k = (0); k <= (int(4) - 1); k++) {
    bool ok = false;
    for (int i = (1); i <= ((n)); i++) {
      int cx = first + i * dx[k];
      int cy = second + i * dy[k];
      if (!good(cx) || !good(cy)) {
        break;
      }
      if (a[cx][cy]) {
        ok = true;
        break;
      }
    }
    if (ok) {
      if (used[first + dx[k]][second + dy[k]]) continue;
      add(code[k]);
      dfs(first + dx[k], second + dy[k]);
      add(rcode[k]);
    }
  }
  add('0');
  a[first][second] = 0;
}
int main() {
  scanf("%d%d%d", &n, &x0, &y234324);
  x0--;
  y234324--;
  for (int i = (0); i <= (int(n) - 1); i++)
    for (int j = (0); j <= (int(n) - 1); j++) scanf("%d", &a[i][j]);
  dfs(x0, y234324);
  bool ok = true;
  for (int i = (0); i <= (int(n) - 1); i++)
    for (int j = (0); j <= (int(n) - 1); j++)
      if (a[i][j] == 1) ok = false;
  if (ok) {
    cout << "YES" << endl;
    ans[m] = 0;
    puts(ans);
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
