#include <bits/stdc++.h>
using namespace std;
long long inv(long long a) {
  long long ans = 1;
  for (int k = 998244353 - 2; k; k >>= 1) {
    if (k & 1) ans = ans * a % 998244353;
    a = a * a % 998244353;
  }
  return ans;
}
int n, m;
int x[55], y[55];
vector<int> T;
long long calc(int T) {
  vector<int> C, Y;
  struct node {
    int x, l, r, d;
    node(int _x, int _l, int _r, int _d) { x = _x, l = _l, r = _r, d = _d; }
    bool operator<(const node& N) const { return x < N.x; }
  };
  vector<node> X;
  for (int i = 1; i <= n; ++i) {
    int ly = y[i] - T, ry = y[i] + T + 1;
    Y.push_back(ly);
    Y.push_back(ry);
    X.push_back(node(x[i] - T, ly, ry, 1));
    X.push_back(node(x[i] + T + 1, ly, ry, -1));
  }
  sort(X.begin(), X.end());
  sort(Y.begin(), Y.end());
  Y.resize(unique(Y.begin(), Y.end()) - Y.begin());
  C.resize(Y.size(), 0);
  long long ans = 0;
  for (int i = 0; i < X.size(); ++i) {
    int l = lower_bound(Y.begin(), Y.end(), X[i].l) - Y.begin(),
        r = lower_bound(Y.begin(), Y.end(), X[i].r) - Y.begin(), d = X[i].d;
    if (i)
      for (int j = 0; j < Y.size(); ++j)
        if (C[j]) {
          assert(j != Y.size() - 1);
          ans = (ans + 1LL * (X[i].x - X[i - 1].x) * (Y[j + 1] - Y[j])) %
                998244353;
        }
    for (int j = l; j < r; ++j) C[j] += d;
  }
  return ans;
}
long long X[10], Fx[10];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%d%d", x + i, y + i);
  T.push_back(m);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) {
      int tx = abs(x[i] - x[j]), ty = abs(y[i] - y[j]),
          t = max((tx + 1) >> 1, (ty + 1) >> 1);
      if (t > m) continue;
      T.push_back(t);
    }
  sort(T.begin(), T.end());
  T.resize(unique(T.begin(), T.end()) - T.begin());
  long long ans = 0;
  for (int i = 0; i < T.size() - 1; ++i) {
    if (T[i] + 4 >= T[i + 1]) {
      for (int t = T[i]; t < T[i + 1]; ++t) ans = (ans + calc(t)) % 998244353;
    } else {
      for (int j = 1; j <= 4; ++j)
        X[j] = T[i] + j - 1, Fx[j] = (calc(X[j]) + Fx[j - 1]) % 998244353;
      long long sum = 0, t = T[i + 1] - 1;
      for (int j = 1; j <= 4; ++j) {
        long long p = 1, q = 1;
        for (int k = 1; k <= 4; ++k)
          if (k != j)
            p = p * (t - X[k] + 998244353) % 998244353,
            q = q * (X[j] - X[k] + 998244353) % 998244353;
        sum = (sum + p * inv(q) % 998244353 * Fx[j]) % 998244353;
      }
      ans = (ans + sum) % 998244353;
    }
  }
  ans = (m * calc(m) - ans + 998244353) % 998244353;
  printf("%lld\n", ans);
  return 0;
}
