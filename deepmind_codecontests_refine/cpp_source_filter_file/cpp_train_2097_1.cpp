#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5, mod = 1e9 + 7;
struct matrix {
  vector<vector<int> > x;
  matrix(int m) {
    x.resize(m + 1);
    for (int i = 0; i <= m; ++i)
      for (int j = 0; j <= m; ++j) x[i].push_back(0);
  }
  void adjust() {
    int m = x.size() - 1;
    x[1][1] = 1;
    x[1][m] = 1;
    for (int i = 2; i <= m; ++i)
      for (int j = 1; j <= m; ++j)
        if (i - 1 == j) {
          x[i][j] = 1;
          break;
        }
  }
  matrix operator*(matrix a) {
    int m = a.x.size() - 1;
    matrix res(m);
    for (int i = 1; i <= m; ++i)
      for (int j = 1; j <= m; ++j)
        for (int k = 1; k <= m; ++k)
          res.x[i][j] = (res.x[i][j] + x[i][k] * a.x[k][j]) % mod;
    return res;
  }
  matrix power(long long b) {
    int m = x.size() - 1;
    matrix res(m);
    res.adjust();
    if (b == 1) return res;
    matrix temp = power(b / 2);
    temp = temp * temp;
    if (b % 2) return temp * res;
    return temp;
  }
};
int main() {
  long long a;
  int m;
  cin >> a >> m;
  matrix cs(m);
  cs.adjust();
  matrix ans = cs.power(a);
  cout << ans.x[1][1];
  return 0;
}
