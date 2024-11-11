#include <bits/stdc++.h>
using namespace std;
vector<string> v;
int n, m, cnt;
void dfs(int i, int j) {
  if (cnt == 0) return;
  v[i][j] = ',';
  cnt--;
  if (i > 0 && v[i - 1][j] == '.') dfs(i - 1, j);
  if (j > 0 && v[i][j - 1] == '.') dfs(i, j - 1);
  if (i < n - 1 && v[i + 1][j] == '.') dfs(i + 1, j);
  if (j < m - 1 && v[i][j + 1] == '.') dfs(i, j + 1);
}
int main() {
  int k, s = 0;
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    v.push_back(s);
  }
  int ii, jj;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (v[i][j] == '.') {
        s++;
        ii = i;
        jj = j;
      }
    }
  }
  cnt = s - k;
  dfs(ii, jj);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (v[i][j] == '.') {
        v[i][j] = 'X';
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (v[i][j] == ',') {
        v[i][j] = '.';
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << v[i] << endl;
  }
  return 0;
}
