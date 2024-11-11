#include <bits/stdc++.h>
using namespace std;
const int N = 102, Q = 10004;
int mat[N][N], n, m;
pair<int, vector<int>> query[Q];
void shiftRow(int i) {
  vector<int> v(mat[i], mat[i] + m);
  for (int j = 0; j < m; ++j) mat[i][(j + 1) % m] = v[j];
}
void shiftCol(int i) {
  vector<int> v(n);
  for (int j = 0; j < n; ++j) v[j] = mat[j][i];
  for (int j = 0; j < n; ++j) mat[(j + 1) % n][i] = v[j];
}
int main() {
  int q;
  scanf("%d %d %d", &n, &m, &q);
  for (int i = 0; i < q; ++i) {
    int t;
    vector<int> v;
    scanf("%d", &t);
    if (t == 1) {
      int r;
      scanf("%d", &r);
      v.push_back(r);
    } else if (t == 2) {
      int c;
      scanf("%d", &c);
      v.push_back(c);
    } else {
      int r, c, x;
      scanf("%d %d %d", &r, &c, &x);
      v.push_back(r);
      v.push_back(c);
      v.push_back(x);
    }
    query[i] = {t, v};
  }
  for (int i = q - 1; i >= 0; --i) {
    int t = query[i].first;
    if (t == 1) {
      int r = query[i].second[0];
      shiftRow(r - 1);
    } else if (t == 2) {
      int c = query[i].second[0];
      shiftCol(c - 1);
    } else {
      int r = query[i].second[0], c = query[i].second[1],
          x = query[i].second[2];
      mat[r - 1][c - 1] = x;
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      printf("%d%c", mat[i][j], " \n"[j + 1 == m]);
    }
  }
}
