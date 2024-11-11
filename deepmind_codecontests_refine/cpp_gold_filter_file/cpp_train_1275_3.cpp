#include <bits/stdc++.h>
using namespace std;
const long long int N = 55;
long long int n, m;
char arr[N][N];
long long int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool valid(long long int i, long long int j) {
  return i >= 1 && i <= n && j >= 1 && j <= m;
}
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (long long int i = 1; i <= n; i++) {
      for (long long int j = 1; j <= m; j++) {
        cin >> arr[i][j];
      }
    }
    for (long long int i = 1; i <= n; i++) {
      for (long long int j = 1; j <= m; j++) {
        if (arr[i][j] == 'B') {
          for (long long int k = 0; k < 4; k++) {
            long long int ni = i + dir[k][0];
            long long int nj = j + dir[k][1];
            if (valid(ni, nj) && arr[ni][nj] == '.') {
              arr[ni][nj] = '#';
            }
          }
        }
      }
    }
    queue<pair<long long int, long long int> > que;
    bool visited[n + 5][m + 5];
    memset(visited, false, sizeof(visited));
    if (arr[n][m] == '.') {
      que.push({n, m});
      visited[n][m] = true;
    }
    while (!que.empty()) {
      pair<long long int, long long int> curr = que.front();
      que.pop();
      for (long long int k = 0; k < 4; k++) {
        long long int ni = curr.first + dir[k][0];
        long long int nj = curr.second + dir[k][1];
        if (valid(ni, nj) && !visited[ni][nj] && arr[ni][nj] != '#') {
          que.push({ni, nj});
          visited[ni][nj] = true;
        }
      }
    }
    bool good = true;
    for (long long int i = 1; i <= n; i++) {
      for (long long int j = 1; j <= m; j++) {
        if ((arr[i][j] == 'G' && !visited[i][j]) ||
            (arr[i][j] == 'B' && visited[i][j])) {
          good = false;
          break;
        }
      }
    }
    if (good)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
}
