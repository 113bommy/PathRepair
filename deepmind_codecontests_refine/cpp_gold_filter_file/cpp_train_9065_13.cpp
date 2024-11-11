#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 7, LOG = (1 << 12);
bool A[N][N], Row[N][LOG], Col[N][LOG];
int U[N][N], D[N][N], R[N][N], L[N][N];
vector<pair<pair<int, int>, int> > Result;
int n, m, p = 1;
int GetMin(int x, int y) {
  return min(U[x][y], min(D[x][y], min(R[x][y], L[x][y])));
}
bool Can(int x, int y) { return GetMin(x, y) > 1; }
void UpdateRow(int L, int R, int row) {
  while (L < R) {
    if (L & 1) Row[row][L++] = true;
    if (R & 1) Row[row][--R] = true;
    L >>= 1;
    R >>= 1;
  }
}
void UpdateCol(int L, int R, int col) {
  while (L < R) {
    if (L & 1) Col[col][L++] = true;
    if (R & 1) Col[col][--R] = true;
    L >>= 1;
    R >>= 1;
  }
}
void Draw(int x, int y) {
  int mini = GetMin(x, y);
  UpdateRow(y - mini + p, y - 1 + mini + p, x);
  UpdateCol(x - mini + p, x - 1 + mini + p, y);
  Result.push_back({{x, y}, mini - 1});
}
bool GetRow(int row, int v) {
  bool result = false;
  while (v) {
    result |= Row[row][v];
    v >>= 1;
  }
  return result;
}
bool GetCol(int col, int v) {
  bool result = false;
  while (v) {
    result |= Col[col][v];
    v >>= 1;
  }
  return result;
}
bool Equals() {
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      if (A[i][j] != (GetCol(j, i - 1 + p) | GetRow(i, j - 1 + p)))
        return false;
  return true;
}
void Read() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      char c;
      scanf(" %c", &c);
      if (c == '*') A[i][j] = true;
    }
}
void Prepare() {
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      if (A[i][j])
        U[i][j] = U[i - 1][j] + 1;
      else
        U[i][j] = 0;
  for (int i = n; i > 0; --i)
    for (int j = 1; j <= m; ++j)
      if (A[i][j])
        D[i][j] = D[i + 1][j] + 1;
      else
        D[i][j] = 0;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      if (A[i][j])
        L[i][j] = L[i][j - 1] + 1;
      else
        L[i][j] = 0;
  for (int i = 1; i <= n; ++i)
    for (int j = m; j > 0; --j)
      if (A[i][j])
        R[i][j] = R[i][j + 1] + 1;
      else
        R[i][j] = 0;
  while (p < max(n, m)) p <<= 1;
}
void Solve() {
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      if (Can(i, j)) Draw(i, j);
  if (Equals()) {
    printf("%d\n", Result.size());
    for (int i = 0; i < Result.size(); ++i)
      printf("%d %d %d\n", Result[i].first.first, Result[i].first.second,
             Result[i].second);
  } else
    printf("-1");
}
int main() {
  Read();
  Prepare();
  Solve();
  return 0;
}
