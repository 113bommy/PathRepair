#include <bits/stdc++.h>
using namespace std;
const int Mod = 1000000007;
int N;
struct Mat {
  long long a[2][2];
  Mat() { memset(a, 0, sizeof(a)); }
  Mat operator*(const Mat &t) const {
    Mat res;
    for (int i = 0; i <= 1; ++i)
      for (int j = 0; j <= 1; ++j)
        for (int k = 0; k <= 1; ++k)
          res.a[i][j] =
              (res.a[i][j] + (long long)a[i][k] * t.a[k][j] % Mod) % Mod;
    return res;
  }
  Mat Power(long long b) {
    Mat res, tmp = *this;
    res.a[0][0] = res.a[1][1] = 1;
    while (b) {
      if (b & 1) res = res * tmp;
      b /= 2;
      tmp = tmp * tmp;
    }
    return res;
  }
};
int main() {
  cin >> N;
  Mat A;
  A.a[0][0] = A.a[1][1] = 3;
  A.a[0][1] = A.a[1][0] = 1;
  A = A.Power(N);
  cout << A.a[0][0] << endl;
  return 0;
}
