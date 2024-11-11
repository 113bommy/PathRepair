#include <bits/stdc++.h>
using namespace std;
template <class T>
void max_swap(T& a, const T& b) {
  a = max(a, b);
}
template <class T>
void min_swap(T& a, const T& b) {
  a = min(a, b);
}
const double EPS = 1e-8;
const double PI = acos(-1.0);
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
int main() {
  int n, c[32][32];
  cin >> n;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) cin >> c[i][j];
  static int row[32], col[32];
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      row[i] += c[i][j];
      col[i] += c[j][i];
    }
  }
  int res = 0;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      if (col[j] > row[i]) ++res;
  cout << res << endl;
}
