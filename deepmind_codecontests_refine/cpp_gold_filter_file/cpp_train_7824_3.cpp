#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
struct Modmat {
  vector<vector<int>> mat;
  int n, m;
  Modmat(int n, int m) : n(n), m(m) { mat.resize(n, vector<int>(m)); }
  vector<int> &operator[](int id) { return mat[id]; }
  Modmat operator+=(Modmat that) {
    assert(n == that.n && m == that.m);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        (mat[i][j] += that.mat[i][j]) %= mod;
      }
    }
    return *this;
  }
  Modmat operator*=(Modmat that) {
    assert(m == that.n);
    Modmat res(n, that.m);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < that.m; j++) {
        for (int k = 0; k < m; k++) {
          res[i][j] = (res[i][j] + (long long)mat[i][k] * that[k][j]) % mod;
        }
      }
    }
    return *this = res;
  }
  Modmat operator+(Modmat that) { return that += *this; }
  Modmat operator*(Modmat that) { return that *= *this; }
};
Modmat full_mat(64, 64);
vector<Modmat> colored_mat(3, Modmat(64, 64));
int select_and_sg(vector<int> a, int f[]) {
  vector<bool> mark(4);
  for (int i = 0; i < 3; i++) {
    if (f[i]) {
      mark[a[i]] = true;
    }
  }
  for (int i = 0; i < 4; i++) {
    if (!mark[i]) {
      return i;
    }
  }
}
int encode(vector<int> a) { return a[0] << 4 | a[1] << 2 | a[2]; }
void build_mat(int f[3][3]) {
  for (int i = 0; i < 256; i++) {
    int a = (i & 192) >> 6, b = (i & 48) >> 4, c = (i & 12) >> 2, d = i & 3;
    for (int j = 0; j < 3; j++) {
      if (a == select_and_sg({b, c, d}, f[j])) {
        colored_mat[j][encode({b, c, d})][encode({a, b, c})] = 1;
        full_mat[encode({b, c, d})][encode({a, b, c})] += 1;
      }
    }
  }
}
vector<int> divide(int x) {
  vector<int> ans;
  while (x > 0) {
    ans.push_back(x & 1);
    x >>= 1;
  }
  return ans;
}
int main() {
  int n, m, xi, yi, ci;
  cin >> n;
  vector<int> a(n);
  for (int &it : a) {
    cin >> it;
  }
  cin >> m;
  vector<vector<pair<int, int>>> colored(n);
  for (int i = 0; i < m; i++) {
    cin >> xi >> yi >> ci;
    colored[--xi].push_back({yi, --ci});
  }
  for (int i = 0; i < n; i++) {
    sort(colored[i].begin(), colored[i].end());
  }
  int f[3][3];
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> f[i][j];
    }
  }
  build_mat(f);
  vector<Modmat> full_mat_pow(30, Modmat(64, 64));
  full_mat_pow[0] = full_mat;
  for (int i = 1; i < 30; i++) {
    full_mat_pow[i] = full_mat_pow[i - 1] * full_mat_pow[i - 1];
  }
  vector<vector<int>> dp(n + 1, vector<int>(4));
  dp[0][0] = 1;
  for (int i = 0; i < n; i++) {
    Modmat cur(1, 64);
    cur[0][encode({3, 3, 3})] = 1;
    int last = 0;
    for (auto &p : colored[i]) {
      auto mi = divide(p.first - last - 1);
      for (int j = 0; j < mi.size(); j++) {
        if (mi[j]) {
          cur *= full_mat_pow[j];
        }
      }
      cur *= colored_mat[p.second];
      last = p.first;
    }
    auto mi = divide(a[i] - last);
    for (int j = 0; j < mi.size(); j++) {
      if (mi[j]) {
        cur *= full_mat_pow[j];
      }
    }
    vector<int> temp(4);
    for (int j = 0; j < 64; j++) {
      (temp[(j & 48) >> 4] += cur[0][j]) %= mod;
    }
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 4; k++) {
        (dp[i + 1][j] += 1ll * dp[i][j ^ k] * temp[k] % mod) %= mod;
      }
    }
  }
  cout << dp[n][0] << endl;
  return 0;
}
