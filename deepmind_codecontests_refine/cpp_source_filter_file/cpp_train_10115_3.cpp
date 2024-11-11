#include <bits/stdc++.h>
using namespace std;
map<string, int> mp;
const int INF = 0x3F3F3F3F;
const int MOD = 1000003;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
vector<vector<char> > mat;
vector<vector<bool> > can[4];
int n, m;
bool isvalid(int x, int y) { return x >= 0 && x < n && y >= 0 && y < m; }
bool check(int x, int y) {
  int tx = x, ty = y;
  bool ok = 0;
  for (int i = 0; i < n; i++) {
    if (mat[i][y] == '.') continue;
    if ((i & 1) == (x & 1)) {
      if (mat[x][y] == '1' || mat[x][y] == '4') {
        ok |= mat[i][y] != '1' && mat[i][y] != '4';
      } else {
        ok |= mat[i][y] != '2' && mat[i][y] != '3';
      }
    } else {
      if (mat[x][y] == '1' || mat[x][y] == '4') {
        ok |= mat[i][y] != '2' && mat[i][y] != '3';
      } else {
        ok |= mat[i][y] != '1' && mat[i][y] != '4';
      }
    }
  }
  for (int i = 0; i < m; i++) {
    if (mat[x][i] == '.') continue;
    if ((i & 1) == (y & 1)) {
      if (mat[x][y] == '1' || mat[x][y] == '2') {
        ok |= mat[x][i] != '1' && mat[x][i] != '2';
      } else {
        ok |= mat[x][i] != '3' && mat[x][i] != '4';
      }
    } else {
      if (mat[x][y] == '1' || mat[x][y] == '2') {
        ok |= mat[x][i] != '3' && mat[x][i] != '4';
      } else {
        ok |= mat[x][i] != '1' && mat[x][i] != '2';
      }
    }
  }
  return ok;
}
int main() {
  cin >> n >> m;
  mat.resize(n);
  for (int i = 0; i < 4; i++) {
    can[i].resize(n);
    for (int j = 0; j < n; j++) {
      can[i][j].resize(m);
    }
  }
  for (int i = 0; i < n; i++) {
    mat[i].resize(m);
    for (int j = 0; j < m; j++) {
      cin >> mat[i][j];
      for (int k = 0; k < 4; k++) {
        can[k][i][j] = 1;
      }
    }
  }
  bool flag = 0;
  for (int i = 0; i < n; i++) {
    if (flag) break;
    bool l[2] = {0};
    for (int j = 0; j < m; j++) {
      if (mat[i][j] == '.') continue;
      if (mat[i][j] == '1' || mat[i][j] == '2') {
        l[j & 1] = 1;
      } else {
        l[(j + 1) & 1] = 1;
      }
    }
    if (l[0] && l[1]) flag = 1;
  }
  for (int j = 0; j < m; j++) {
    if (flag) break;
    bool u[2] = {0};
    for (int i = 0; i < n; i++) {
      if (mat[i][j] == '.') continue;
      if (mat[i][j] == '1' || mat[i][j] == '4') {
        u[j & 1] = 1;
      } else {
        u[(j + 1) & 1] = 1;
      }
    }
    if (u[0] && u[1]) flag = 1;
  }
  if (flag) {
    cout << 0 << endl;
    return 0;
  }
  int num = n + m;
  for (int i = 0; i < n; i++) {
    if (count(mat[i].begin(), mat[i].end(), '.') != m) {
      num--;
    }
  }
  for (int j = 0; j < m; j++) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (mat[i][j] == '.') {
        cnt++;
      }
    }
    if (cnt != n) {
      num--;
    }
  }
  int ans = 1;
  for (int i = 0; i < num; i++) {
    ans = (ans * 2) % MOD;
  }
  cout << ans << endl;
}
