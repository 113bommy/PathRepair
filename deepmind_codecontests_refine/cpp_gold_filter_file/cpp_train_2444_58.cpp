#include <bits/stdc++.h>
using namespace std;
const int dim = 55;
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};
int n, m;
char a[55][55];
bool viz[dim * dim], dus[dim * dim][dim * dim], RASPUNS = 0;
int b[dim][dim];
vector<int> vec[dim * dim];
bool Valid(int x, int y) { return (x >= 0 && x < n && y >= 0 && y < m); }
void DFS(int u) {
  viz[u] = 1;
  vector<int>::iterator j;
  for (j = vec[u].begin(); j < vec[u].end(); j++) {
    if (!viz[*j]) {
      dus[u][*j] = 1;
      dus[*j][u] = 1;
      DFS(*j);
    } else {
      if (dus[u][*j] == 0) {
        RASPUNS = 1;
      }
    }
  }
}
int main() {
  int i, j, cnt = 1, k;
  cin >> n >> m;
  for (i = 0; i < n; i++) {
    cin >> a[i];
    for (j = 0; j < m; j++) {
      b[i][j] = cnt;
      cnt++;
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      for (k = 0; k < 4; k++) {
        if (Valid(i + di[k], j + dj[k]) && a[i][j] == a[i + di[k]][j + dj[k]]) {
          vec[b[i][j]].push_back(b[i + di[k]][j + dj[k]]);
          vec[b[i + di[k]][j + dj[k]]].push_back(b[i][j]);
        }
      }
    }
  }
  for (i = 1; i <= n * m; i++) {
    if (!viz[i]) {
      DFS(i);
    }
  }
  if (RASPUNS == 0) {
    cout << "No";
  } else
    cout << "Yes";
  return 0;
}
