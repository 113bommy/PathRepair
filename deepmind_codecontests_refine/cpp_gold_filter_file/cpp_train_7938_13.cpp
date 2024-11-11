#include <bits/stdc++.h>
using namespace std;
long long int max(long long int a, long long int b) {
  if (a > b)
    return a;
  else
    return b;
}
long long int min(long long int a, long long int b) {
  if (a < b)
    return a;
  else
    return b;
}
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
int XX[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int YY[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  long long int i, j, u, v, t, x, y, l, r, n, k, a, b, g, w, m, Sx, Sy;
  cin >> n >> m >> Sx >> Sy;
  bool visited[105][105];
  memset(visited, false, sizeof(visited));
  visited[Sx][Sy] = 1;
  cout << Sx << " " << Sy << "\n";
  while (true) {
    long long int flag = 0;
    for (j = 1; j <= m; j++) {
      if (!visited[Sx][j]) {
        visited[Sx][j] = 1;
        cout << Sx << " " << j << "\n";
        Sy = j;
        flag = 1;
        break;
      }
    }
    if (flag == 0) {
      for (i = 1; i <= n; i++) {
        if (!visited[i][Sy]) {
          visited[i][Sy] = 1;
          cout << i << " " << Sy << "\n";
          Sx = i;
          flag = 1;
          break;
        }
      }
    }
    if (flag == 0) break;
  }
}
