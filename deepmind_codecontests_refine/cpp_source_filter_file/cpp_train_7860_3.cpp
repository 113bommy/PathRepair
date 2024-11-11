#include <bits/stdc++.h>
using namespace std;
int mat[600][600];
set<int> marka;
set<int> markc;
set<int> markb;
int main() {
  int n, m, x, y;
  int a, c;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    mat[x][y] = 1;
    mat[y][x] = 1;
  }
  if (m == n * (n - 1) / 2) {
    cout << "Yes" << endl;
    for (int i = 0; i < n; i++) {
      cout << "a";
    }
    return 0;
  }
  int flag = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (mat[i][j] == 0) {
        flag = 1;
        a = i;
        c = j;
        break;
      }
    }
    if (flag) break;
  }
  if (flag == 0) {
    cout << "No" << endl;
    return 0;
  }
  marka.insert(a);
  markb.insert(c);
  flag = 0;
  for (int i = 1; i <= n; i++) {
    if (i == a || i == c) continue;
    if (mat[a][i] && mat[i][c])
      markb.insert(i);
    else if (mat[a][i])
      marka.insert(i);
    else if (mat[i][c])
      markc.insert(i);
    else {
      flag = 1;
      break;
    }
  }
  if (flag == 1) {
    cout << "No" << endl;
    return 0;
  }
  for (int i = 1; i < n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (mat[i][j]) {
        if (marka.find(i) != marka.end() && markc.find(j) != markc.end())
          flag = 1;
        if (marka.find(j) != marka.end() && markc.find(i) != markc.end())
          flag = 1;
      } else {
        if ((!(marka.find(i) != marka.end() && markc.find(j) != markc.end())) &&
            (!(marka.find(j) != marka.end() && markc.find(i) != markc.end())))
          flag = 1;
      }
      if (flag) break;
    }
    if (flag) break;
  }
  if (flag) {
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
  for (int i = 1; i <= n; i++) {
    if (marka.find(i) != marka.end()) cout << "a";
    if (markb.find(i) != markb.end()) cout << "b";
    if (markc.find(i) != markc.end()) cout << "c";
  }
  return 0;
}
