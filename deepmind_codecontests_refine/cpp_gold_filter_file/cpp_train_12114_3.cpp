#include <bits/stdc++.h>
using namespace std;
long long mod, l, r, k;
long long getbest() {
  long long best = 0;
  long long last = 1;
  while (last <= r) {
    long long i = last;
    long long val = r / i;
    i = r / val;
    if (r / i - (l - 1) / i >= k) best = i;
    last = i + 1;
  }
  return best;
}
vector<vector<long long>> mul(vector<vector<long long>>& a,
                              vector<vector<long long>>& b) {
  vector<vector<long long>> c = {{0LL, 0LL}, {0LL, 0LL}};
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j)
      for (int k = 0; k < 2; ++k) c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % mod;
  }
  return c;
}
vector<vector<long long>> fastexp(vector<vector<long long>> A, long long e) {
  vector<vector<long long>> res = {{1LL, 0LL}, {0LL, 1LL}};
  while (e) {
    if (e & 1) res = mul(res, A);
    e >>= 1;
    A = mul(A, A);
  }
  return res;
}
long long fib(long long ind) {
  int f1 = 1, f2 = 1;
  if (ind <= 2) return 1;
  vector<vector<long long>> A = {{0LL, 1LL}, {1LL, 1LL}};
  A = fastexp(A, ind - 1);
  return (A[0][0] + A[0][1]) % mod;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> mod >> l >> r >> k;
  long long best = getbest();
  cout << (fib(best) % mod);
}
