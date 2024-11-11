#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
vector<vector<long long>> operator*(vector<vector<long long>> a,
                                    vector<vector<long long>> b) {
  if (a[0].size() != b.size()) swap(a, b);
  int n = a.size();
  int m = b[0].size();
  vector<vector<long long>> c(n, vector<long long>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int k = 0; k < b.size(); k++) {
        (c[i][j] += a[i][k] * b[k][j]) %= mod;
      }
    }
  }
  return c;
}
vector<vector<long long>> bpow(vector<vector<long long>> a, long long b) {
  assert(b >= 0);
  if (b == 1) return a;
  if (b & 1) return a * bpow(a, b - 1);
  auto t = bpow(a, b / 2);
  return t * t;
}
long long bpow(long long a, long long b) {
  if (!b) return 1;
  if (b & 1) return a * bpow(a, b - 1) % mod;
  long long t = bpow(a, b / 2);
  return t * t % mod;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, f1, f2, f3, c;
  cin >> n >> f1 >> f2 >> f3 >> c;
  vector<vector<long long>> d = {{0, 1, 0}, {0, 0, 1}, {1, 1, 1}};
  d = bpow(d, n - 3);
  vector<vector<long long>> v1 = {{1}, {0}, {0}};
  vector<vector<long long>> v2 = {{0}, {1}, {0}};
  vector<vector<long long>> v3 = {{0}, {0}, {1}};
  long long deg1 = (v1 * d).back().back(), deg2 = (v2 * d).back().back(),
            deg3 = (v3 * d).back().back();
  vector<vector<long long>> C = {{0, 1, 0, 0, 0},
                                 {0, 0, 1, 0, 0},
                                 {1, 1, 1, 2, -6},
                                 {0, 0, 0, 1, 1},
                                 {0, 0, 0, 0, 1}};
  C = bpow(C, n - 3);
  C = C * (vector<vector<long long>>){{0}, {0}, {0}, {4}, {1}};
  cout << bpow(c, C[2][0]) * bpow(f1, deg1) % mod * bpow(f2, deg2) % mod *
              bpow(f3, deg3) % mod;
}
