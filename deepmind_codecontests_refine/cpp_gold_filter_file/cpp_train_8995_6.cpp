#include <bits/stdc++.h>
using namespace std;
int mod;
vector<vector<long long>> mul(vector<vector<long long>> a,
                              vector<vector<long long>> b) {
  int n = a.size();
  int m = b[0].size();
  int k = b.size();
  vector<vector<long long>> c(n, vector<long long>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int z = 0; z < k; z++) {
        c[i][j] = (c[i][j] + a[i][z] * b[z][j]) % mod;
      }
    }
  }
  return c;
}
vector<vector<long long>> fast_pow(vector<vector<long long>> a, long long p) {
  p--;
  vector<vector<long long>> res = a;
  while (p) {
    if (p % 2 == 0) {
      a = mul(a, a);
      p /= 2;
    } else {
      res = mul(res, a);
      p--;
    }
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  vector<vector<long long>> v = {
      {1, 0, 1, 0, 0, 0}, {0, 1, 0, 1, 0, 0}, {1, 1, 2, 1, 0, 0},
      {1, 1, 1, 2, 0, 0}, {1, 1, 1, 1, 1, 0}, {2, 2, 2, 2, 1, 1},
  };
  long long n, sx, sy, dx, dy, t;
  cin >> n >> sx >> sy >> dx >> dy >> t;
  mod = n;
  vector<vector<long long>> a = {
      {(dx % mod + mod) % mod, (dy % mod + mod) % mod, sx - 1, sy - 1, 0, 1}};
  if (t) {
    v = fast_pow(v, t);
    a = mul(a, v);
  }
  cout << a[0][2] + 1 << " " << a[0][3] + 1 << "\n";
}
