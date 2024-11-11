#include <bits/stdc++.h>
using namespace std;
vector<int> v[2];
int n;
vector<vector<int> > color;
vector<vector<int> > degree;
void coloring(int i, int j) {
  int n_p = !j;
  for (int m = 0; m < v[n_p].size(); ++m) {
    int x = v[n_p][m];
    int pos;
    if ((i - x) >= 0)
      pos = i - x;
    else
      pos = i - x + n;
    if (color[pos][n_p]) continue;
    if (color[i][j] == 1) {
      degree[pos][n_p]--;
      if (degree[pos][n_p] == 0) {
        color[pos][n_p] = 2;
        coloring(pos, n_p);
      }
    } else {
      color[pos][n_p] = 1;
      coloring(pos, n_p);
    }
  }
}
int main() {
  cin >> n;
  int k;
  cin >> k;
  v[0].resize(k);
  color.assign(n, vector<int>(2));
  degree.assign(n, vector<int>(2));
  for (int i = 0; i < k; i++) {
    cin >> v[0][i];
  }
  for (int i = 0; i < n; ++i) {
    degree[i][0] = k;
  }
  cin >> k;
  v[1].resize(k);
  for (int i = 0; i < k; i++) {
    cin >> v[1][i];
  }
  for (int i = 0; i < n; ++i) {
    degree[i][1] = k;
  }
  color[0][0] = color[0][1] = 2;
  coloring(0, 0);
  coloring(0, 1);
  for (int j = 0; j < 2; ++j) {
    for (int i = 1; i < n; ++i) {
      if (color[i][j] == 1)
        cout << "Win ";
      else if (color[i][j] == 2)
        cout << "Lose ";
      else
        cout << "Loop ";
    }
    cout << endl;
  }
}
