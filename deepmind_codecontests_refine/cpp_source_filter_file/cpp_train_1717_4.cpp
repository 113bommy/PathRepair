#include <bits/stdc++.h>
using namespace std;
long long n, k, l;
int M;
vector<vector<long long> > mul(vector<vector<long long> > v,
                               vector<vector<long long> > q) {
  vector<vector<long long> > R(2, vector<long long>(2, 0));
  for (int k = 0; k < 2; ++k)
    for (int i = 0; i < 2; ++i)
      for (int j = 0; j < 2; ++j) R[i][j] = (R[i][j] + v[i][k] * q[k][j]) % M;
  return R;
}
vector<vector<long long> > Pow(vector<vector<long long> > b, long long p) {
  if (p == 1) return b;
  vector<vector<long long> > z = Pow(b, p / 2);
  if (p & 1) return mul(mul(z, z), b);
  return mul(z, z);
}
long long Pow(int b, long long p) {
  if (!p) return 1;
  long long z = Pow(b, p / 2);
  if (p & 1) return z * z % M * b % M;
  return z * z % M;
}
int main() {
  vector<vector<long long> > a(2, vector<long long>(2, 1));
  a[1][1] = 0;
  cin >> n >> k >> l >> M;
  long long no = Pow(a, n + 3)[1][1] % M;
  no = (no + M) % M;
  long long way = ((Pow(2, n) - no) % M + M) % M;
  unsigned long long ONE = 1;
  long long res = 1;
  for (int b = 0; b < 64; ++b) {
    if (k & ONE) {
      if (b >= l) {
        puts("0");
        return 0;
      }
      res = res * way % M;
    } else if (b < l)
      res = res * no % M;
    ONE *= 2;
  }
  cout << (res % M + res) % M;
  return 0;
}
