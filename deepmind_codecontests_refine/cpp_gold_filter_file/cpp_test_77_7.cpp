#include <bits/stdc++.h>
using namespace std;
int n, m, x, k, room;
int area[1000006];
int a[1003][1003];
bool b[1003][1003];
void DFS(int i, int j) {
  if ((i < 1) || (i > n) || (j < 1) || (j > m)) {
  } else {
    int d = a[i][j];
    b[i][j] = true;
    area[room]++;
    if (d % 2 == 0) {
      if (b[i][j - 1] == false) DFS(i, j - 1);
    };
    d = d / 2;
    if (d % 2 == 0) {
      if (b[i + 1][j] == false) DFS(i + 1, j);
    };
    d = d / 2;
    if (d % 2 == 0) {
      if (b[i][j + 1] == false) DFS(i, j + 1);
    };
    d = d / 2;
    if (d % 2 == 0) {
      if (b[i - 1][j] == false) DFS(i - 1, j);
    };
  }
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> a[i][j];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      if (b[i][j] == false) {
        room++;
        DFS(i, j);
      }
    }
  sort(area + 1, area + room + 1);
  for (int i = room; i >= 1; i--) cout << area[i] << ' ';
  return 0;
}
