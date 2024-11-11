#include <bits/stdc++.h>
using namespace std;
long long labs(long long a) { return a < 0 ? (-a) : a; }
long long max(long long a, long long b) { return a > b ? a : b; }
long long min(long long a, long long b) { return a < b ? a : b; }
const int MAXN = 505;
int n, m, k;
char mask[MAXN][MAXN];
int mas[MAXN][MAXN];
bool CheckStar(int i, int j) {
  return (i - 1 < 0 ? 0 : mask[i - 1][j] == '1') &&
         (j - 1 < 0 ? 0 : mask[i][j - 1] == '1') &&
         (i - 1 < 0 || j - 1 < 0 ? 0 : mask[i - 1][j - 1] == '1') &&
         (i - 1 < 0 || j - 2 < 0 ? 0 : mask[i - 1][j - 2] == '1') &&
         (i - 2 < 0 || j - 1 < 0 ? 0 : mask[i - 2][j - 1] == '1');
}
int GetSum(int x, int y, int xx, int yy) {
  int res = mas[xx][yy];
  res -= mas[x + 1][yy];
  res -= mas[xx][y + 1];
  res += mas[x + 1][y + 1];
  return res;
}
struct Cmp : public binary_function<int, int, bool> {
  int x, y, h;
  Cmp(int _x, int _y, int _h) : x(_x), y(_y), h(_h) {}
  bool operator()(int val) const { return GetSum(x, y, h, val) < k; }
};
int BinarySearch(int i, int j, int ii, int jl, int jr) {
  Cmp cmp(i, j, ii);
  while (jl < jr) {
    int jj = (jl + jr) / 2;
    if (cmp(jj)) {
      jl = jj + 1;
    } else {
      jr = jj;
    }
  }
  if (cmp(jl)) {
    jl++;
  }
  return jl;
}
int main() {
  scanf("%d %d %d\n", &n, &m, &k);
  for (int(i) = 0; (i) < (n); (i)++) {
    gets(mask[i]);
  }
  for (int i = 1; i < n; ++i) {
    for (int j = 1; j < m; ++j) {
      mas[i][j] =
          CheckStar(i, j) + mas[i - 1][j] + mas[i][j - 1] - mas[i - 1][j - 1];
    }
  }
  long long res = 0;
  for (int(i) = 0; (i) < (n - 2); (i)++) {
    for (int(j) = 0; (j) < (m - 2); (j)++) {
      for (int ii = i + 2; ii < n; ++ii) {
        res += m - max(j + 2, BinarySearch(i, j, ii, j, m - 1));
      }
    }
  }
  cout << res << endl;
  return 0;
}
