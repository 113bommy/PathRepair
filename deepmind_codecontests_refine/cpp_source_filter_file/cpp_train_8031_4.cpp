#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, e1, e2, f1, f2, m, n, v, min, stair(0);
  bool flag = true;
  typedef char* intPoint;
  intPoint* graph;
  cin >> m >> n;
  graph = new intPoint[m];
  for (i = 0; i < m; i++) graph[i] = new char[n];
  f1 = 0;
  e1 = 0;
  for (i = 0; i < n; i++) {
    cin >> graph[0][i];
    if (graph[0][i] == 'W') e1 = i;
  }
  min = 0;
  v = 0;
  for (i = 1; i < m; i++) {
    for (j = 0; j < n; j++) {
      cin >> graph[i][j];
      if (graph[i][j] == 'W') {
        if (flag) {
          f2 = j;
          flag = false;
        }
        e2 = j;
      }
    }
    if (flag) v++;
    if ((!flag) && (v > 0)) {
      if (v % 2 == 1) {
        if ((i - 1) % 2 == 0) {
          min += e1 - f1;
          f1 = e1;
        } else {
          min += e1 - f1;
          e1 = f1;
        }
      }
      v = 0;
    }
    if (!flag) {
      stair = i;
      if (i % 2 == 1) {
        if (e2 > e1) {
          min += e2 - f1;
          e1 = e2;
        } else
          min += e1 - f1;
        f1 = f2;
      } else {
        if (f1 < f2)
          min += e1 - f1;
        else {
          min += e1 - f2;
          f1 = f2;
        }
        e1 = e2;
      }
      flag = true;
    }
  }
  min += e1 - f1;
  cout << min + stair << endl;
  return 0;
}
