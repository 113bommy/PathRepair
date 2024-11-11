#include <bits/stdc++.h>
using namespace std;
double pi = 3.1415926536;
const int oo = (int)1e9;
const long long OO = numeric_limits<long long>::max();
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int di[] = {0, 0, 1, -1, 1, 1, -1, -1};
int dj[] = {1, -1, 0, 0, 1, -1, 1, -1};
int n, m, k;
string arr[501];
bool memo[501][501];
bool check(int i, int j) { return i >= 0 && i < n && j >= 0 && j < m; }
void dfs(int x, int y) {
  memo[x][y] = 1;
  for (int i = 0; i < 4; i++) {
    int idx1 = x + dx[i];
    int idx2 = y + dy[i];
    if (k && check(idx1, idx2) && arr[idx1][idx2] == '.' && !memo[idx1][idx2])
      dfs(idx1, idx2);
  }
  if (k) {
    arr[x][y] = 'X';
    k--;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) cin >> arr[i];
  bool flag = false;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (arr[i][j] == '.') {
        flag = true;
        dfs(i, j);
        break;
      }
    }
    if (flag) break;
  }
  for (int i = 0; i < n; i++) cout << arr[i] << endl;
}
