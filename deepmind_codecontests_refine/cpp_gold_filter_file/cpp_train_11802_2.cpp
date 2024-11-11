#include <bits/stdc++.h>
using namespace std;
char _;
const long long maxN = 1000 * 1000 + 5;
const long long mod = 1000 * 1000 * 1000 + 7;
const long long base = 701;
const long long SQ = 330;
long long m;
struct Mat {
  long long a[2][2];
  Mat(long long fl = 0) {
    for (long long i = 0; i < 2; i++)
      for (long long j = 0; j < 2; j++)
        if (i == j)
          a[i][j] = fl;
        else
          a[i][j] = 0;
  }
};
Mat operator*(const Mat &p, const Mat &q) {
  Mat ans;
  for (long long i = 0; i < 2; i++)
    for (long long j = 0; j < 2; j++)
      for (long long k = 0; k < 2; k++)
        ans.a[i][j] = (ans.a[i][j] + p.a[i][k] * q.a[k][j] % m) % m;
  return ans;
}
Mat power(Mat p, long long k) {
  Mat ans(1);
  while (k) {
    if (k & 1) ans = ans * p;
    k >>= 1;
    p = p * p;
  }
  return ans;
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long l, r, k;
  cin >> m >> l >> r >> k;
  vector<long long> v;
  for (long long i = 1; i * i <= r; i++) {
    v.push_back(i);
    v.push_back(r / i);
  }
  for (long long i = 1; i * i <= l; i++)
    if (l % i == 0)
      v.push_back(l / i);
    else
      v.push_back(l / (i - 1));
  long long res = 1;
  for (long long i = 0; i < (long long)v.size(); i++) {
    long long ted = (r / v[i]) - ((l - 1) / v[i]);
    if (ted >= k) res = max(res, v[i]);
  }
  long long lo = res;
  Mat p;
  for (long long i = 0; i < 2; i++)
    for (long long j = 0; j < 2; j++) p.a[i][j] = 1;
  p.a[1][1] = 0;
  p = power(p, lo - 1);
  cout << p.a[0][0] % m << endl;
  return 0;
}
