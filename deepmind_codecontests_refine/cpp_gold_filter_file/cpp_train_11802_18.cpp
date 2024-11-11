#include <bits/stdc++.h>
using namespace std;
const int maxi = 1e6 + 10;
const long long mo = 1e9 + 7;
long long a[maxi];
long long m, l, r, k;
string s;
vector<int> v[maxi];
long long mat[53][3][3];
void mul_mat(int idx1, int idx2, int idx) {
  for (int i = 1; i <= 2; i++)
    for (int j = 1; j <= 2; j++)
      for (int k = 1; k <= 2; k++)
        mat[idx][i][j] += mat[idx1][i][k] * mat[idx2][k][j];
  for (int i = 1; i <= 2; i++)
    for (int j = 1; j <= 2; j++) mat[idx][i][j] %= m;
}
void fib(long long x) {
  long long fi = 1;
  long long fj = 1;
  mat[51][1][1] = 1;
  mat[51][2][2] = 1;
  for (int i = 0; i <= 50; i++)
    if (x & (1ll << i)) {
      mul_mat(i, 51, 52);
      for (int j = 1; j <= 2; j++)
        for (int o = 1; o <= 2; o++) {
          mat[51][j][o] = mat[52][j][o];
          mat[52][j][o] = 0;
        }
    }
  cout << mat[51][2][1] << endl;
  return;
}
int main() {
  cin >> m >> l >> r >> k;
  long long x = 1;
  mat[0][1][1] = 1;
  mat[0][1][2] = 1;
  mat[0][2][1] = 1;
  mat[0][2][2] = 0;
  for (long long i = 1; i * i <= r; i++) {
    long long last = r / i;
    long long first = (r / (i + 1)) + 1;
    if (i - k >= 0) {
      long long val = i - k;
      long long li = last;
      long long ri = first + 1;
      while (li < ri - 1) {
        long long mid = (li + ri) / 2;
        if ((l - 1) / mid <= val)
          li = mid;
        else
          ri = mid;
      }
      if ((l - 1) / li <= val) {
        x = max(x, li);
      }
    }
  }
  long long sqr = floor(sqrt(r));
  for (long long num = sqr; num > 0; num--) {
    long long i = r / num;
    long long last = r / i;
    long long first = r / (i + 1) + 1;
    if (i - k >= 0) {
      long long val = i - k;
      long long li = last;
      long long ri = first + 1;
      while (li < ri - 1) {
        long long mid = (li + ri) / 2;
        if ((l - 1) / mid <= val)
          li = mid;
        else
          ri = mid;
      }
      if ((l - 1) / li <= val) {
        x = max(x, li);
      }
    }
  }
  for (int i = 1; i <= 50; i++) mul_mat(i - 1, i - 1, i);
  fib(x);
  return 0;
}
