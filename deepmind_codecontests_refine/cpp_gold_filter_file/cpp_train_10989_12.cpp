#include <bits/stdc++.h>
using namespace std;
long long n;
struct matrix {
  long long w[3][3];
  inline matrix operator*(const matrix& x) const {
    matrix ans;
    for (int i = 0; i < 3; ++i)
      for (int j = 0; j < 3; ++j) {
        ans.w[i][j] = 0;
        for (int k = 0; k < 3; ++k) ans.w[i][j] += w[i][k] * x.w[k][j];
      }
    return ans;
  }
} key, t;
bool check(long long x) {
  --x;
  matrix tp = t, kk = key;
  while (x) {
    if (x & 1) tp = kk * tp;
    kk = kk * kk, x >>= 1;
  }
  return tp.w[2][0] <= n;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  key.w[0][0] = key.w[0][1] = key.w[1][0] = key.w[2][1] = 1;
  t.w[0][0] = 5, t.w[1][0] = 3, t.w[2][0] = 2;
  long long l = 1, r = 85, mid;
  for (int i = 1; i < 10; ++i) check(i);
  while (l < r)
    if (check(mid = l + r + 1 >> 1))
      l = mid;
    else
      r = mid - 1;
  cout << l << endl;
  return 0;
}
