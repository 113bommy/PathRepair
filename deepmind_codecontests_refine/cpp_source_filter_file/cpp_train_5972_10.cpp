#include <bits/stdc++.h>
using namespace std;
const int nax = 1e2 + 11;
int A[nax][nax];
int X[nax], Y[nax], sx[nax], sy[nax];
void go(vector<int> &A) {
  cout << A.size() << " ";
  for (auto v : A) cout << v << " ";
  cout << '\n';
}
int main() {
  int N, M, i, x, y, j;
  cin >> N >> M;
  for (x = 1; x <= N; ++x)
    for (y = 1; y <= M; ++y) {
      cin >> A[x][y];
      sx[x] += A[x][y];
      sy[y] += A[x][y];
    }
  for (;;) {
    bool flag = 0;
    for (x = 1; x <= N; ++x) {
      if (sx[x] < 0) {
        flag = 1;
        X[x] ^= 1;
        sx[x] *= -1;
        for (y = 1; y <= M; ++y) {
          sy[y] += -(((X[x] ^ 1) == 0) ? 1 : -1) * (((Y[y]) == 0) ? 1 : -1) *
                   A[x][y];
          sy[y] +=
              (((X[x]) == 0) ? 1 : -1) * (((Y[y]) == 0) ? 1 : -1) * A[x][y];
        }
      }
    }
    for (y = 1; y <= M; ++y) {
      if (sy[y] < 0) {
        Y[y] ^= 1;
        sy[y] *= -1;
        flag = 1;
        for (x = 1; x <= N; ++x) {
          sx[x] += -(((Y[y] ^ 1) == 0) ? 1 : -1) * (((X[x]) == 0) ? 1 : -1) *
                   A[x][y];
          sx[x] +=
              (((Y[y]) == 0) ? 1 : -1) * (((X[x]) == 0) ? 1 : -1) * A[x][y];
        }
      }
    }
    if (!flag) break;
  }
  vector<int> out1, out2;
  for (x = 1; x <= N; ++x)
    if (X[x]) out1.push_back(x);
  for (x = 1; x <= M; ++x)
    if (Y[x]) out2.push_back(y);
  go(out1);
  go(out2);
  return 0;
}
