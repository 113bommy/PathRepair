#include <bits/stdc++.h>
using namespace std;
const int MAX = 105;
int n, m, q;
int matrix[MAX][MAX];
void rowrun(int x) {
  int t = matrix[x - 1][n - 1];
  for (int i = m - 1; i > 0; i--) {
    matrix[x - 1][i] = matrix[x - 1][i - 1];
  }
  matrix[x - 1][0] = t;
}
void rowrun1(int x) {
  int t = matrix[x - 1][0];
  for (int i = 0; i < m - 1; i++) {
    matrix[x - 1][i] = matrix[x - 1][i + 1];
  }
  matrix[x - 1][m - 1] = t;
}
void colrun(int x) {
  int t = matrix[n - 1][x - 1];
  for (int i = n - 1; i > 0; i--) {
    matrix[i][x - 1] = matrix[i - 1][x - 1];
  }
  matrix[0][x - 1] = t;
}
void colrun1(int x) {
  int t = matrix[0][x - 1];
  for (int i = 0; i < n - 1; i++) {
    matrix[i][x - 1] = matrix[i + 1][x - 1];
  }
  matrix[n - 1][x - 1] = t;
}
int main() {
  while (~scanf("%d%d%d", &n, &m, &q)) {
    memset(matrix, 0, sizeof(matrix));
    stack<pair<int, int> > ss;
    int a, b, c, d;
    for (int i = 0; i < q; i++) {
      scanf("%d", &a);
      if (a != 3) {
        scanf("%d", &b);
        if (a == 1)
          rowrun1(b);
        else
          colrun1(b);
        ss.push(make_pair(a, b));
      } else {
        scanf("%d%d%d", &b, &c, &d);
        matrix[b - 1][c - 1] = d;
      }
    }
    while (!ss.empty()) {
      pair<int, int> res = ss.top();
      ss.pop();
      if (res.first == 1)
        rowrun(res.second);
      else if (res.first == 2)
        colrun(res.second);
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        printf("%d%c", matrix[i][j], j == m - 1 ? '\n' : ' ');
      }
    }
  }
  return 0;
}
