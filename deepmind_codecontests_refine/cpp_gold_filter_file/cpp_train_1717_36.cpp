#include <bits/stdc++.h>
using namespace std;
const double pi = 3.141592653589793238463;
long long m;
long long mod(long long x) { return (x % m + m) % m; }
long long mult(long long x, long long y) { return mod((x % m) * (y % m)); }
long long add(long long x, long long y) { return mod((x % m) + (y % m)); }
long long power(long long b, long long e) {
  long long ans = 1;
  b = b % m;
  while (e) {
    if (e % 2) ans = (ans * b) % m;
    b = (b * b) % m;
    e /= 2;
  }
  return ans;
}
void setSize(vector<vector<long long> > &a, int n) {
  a.resize(n);
  for (auto &row : a) row.resize(n);
}
vector<vector<long long> > matmul(vector<vector<long long> > a,
                                  vector<vector<long long> > b) {
  int n = a.size();
  vector<vector<long long> > c;
  setSize(c, n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      c[i][j] = 0;
      for (int k = 0; k < n; k++)
        c[i][j] = add(c[i][j], mult(a[i][k], b[k][j]));
    }
  return c;
}
vector<vector<long long> > matpow(vector<vector<long long> > a, long long e) {
  vector<vector<long long> > ans = {{1, 0}, {0, 1}};
  while (e) {
    if (e % 2) ans = matmul(ans, a);
    a = matmul(a, a);
    e /= 2;
  }
  return ans;
}
void matprint(vector<vector<long long> > a) {
  for (auto row : a) {
    for (auto x : row) cout << x << " ";
    cout << '\n';
  }
}
long long fib(long long n) {
  if (n == 0) return 0;
  if (n == 1) return 1;
  vector<vector<long long> > M = {{0, 1}, {1, 1}};
  M = matpow(M, n);
  return M[0][1];
}
int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);
  long long n, k, l;
  cin >> n >> k >> l >> m;
  if (m == 1) return cout << (0) << '\n', 0;
  ;
  long long sol0 = fib(n + 2);
  long long sol1 = add(power(2, n), -sol0);
  bitset<64> K = k;
  long long ans = 1;
  for (int bit = 0; bit < l; bit++) {
    if (K[bit])
      ans = mult(ans, sol1);
    else
      ans = mult(ans, sol0);
    K[bit] = 0;
  }
  if (K.any())
    cout << 0 << '\n';
  else
    cout << ans << '\n';
  return 0;
}
