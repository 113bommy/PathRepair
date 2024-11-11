#include <bits/stdc++.h>
using namespace std;
const int maxn = 101;
long long det;
long long mod = 1000000 + 3;
inline int solve(long long a[][maxn], bool l[], long long ans[], const int &n,
                 const int &m) {
  int res = 0, r = 0;
  for (int i = 0; i < n; ++i) l[i] = false;
  for (int i = 0; i < n; ++i) {
    for (int j = r; j < m; ++j)
      if (a[j][i]) {
        for (int k = i; k <= n; ++k) swap(a[j][k], a[r][k]);
        break;
      }
    if (a[r][i] == 0) {
      ++res;
      continue;
    }
    for (int j = 0; j < m; ++j)
      if (j != r && a[j][i]) {
        int ta = a[r][i];
        int tb = a[j][i];
        for (int k = 0; k <= n; ++k) {
          a[j][k] = ((a[j][k] * ta - a[r][k] * tb) % mod + mod) % mod;
        }
      }
    l[i] = true, ++r;
  }
  det = 1;
  for (int i = 0; i < n; ++i) det *= a[i][i];
  for (int i = n - res; i < m; ++i) {
    if (a[i][n]) return -1;
  }
  for (int i = 0; i < n; ++i) {
    if (l[i]) {
      for (int j = 0; j < n; ++j) {
        if (a[j][i] > 0) {
          for (ans[i] = 0; ans[i] < mod; ++ans[i])
            if ((ans[i] * a[j][i] + mod) % mod == a[j][n]) break;
        }
      }
    }
  }
  return res;
}
long long p[50] = {2,   3,   5,   7,   11,  13,  17,  19,  23,  29,
                   31,  37,  41,  43,  47,  53,  59,  61,  67,  71,
                   73,  79,  83,  89,  97,  101, 103, 107, 109, 113,
                   127, 131, 137, 139, 149, 151, 157, 163, 167, 173,
                   179, 181, 191, 193, 197, 199, 211, 223, 227, 229};
long long ans[maxn];
long long a[maxn][maxn];
long long f(long long x) {
  long long sum = 0, pre = 1;
  for (int i = 0; i <= 10; i++) {
    sum = (sum + ans[i] * pre % mod) % mod;
    pre = pre * x % mod;
  }
  return sum;
}
int main() {
  bool l[maxn];
  int n, m, res;
  for (long long i = 0; i < 50; ++i) {
    long long pre = 1;
    for (long long j = 0; j <= 10; ++j) {
      a[i][j] = pre;
      pre = pre * (p[i]) % mod;
    }
  }
  n = 11;
  m = 50;
  for (int i = 0; i < 50; ++i) {
    cout << "? " << p[i] << endl;
    cin >> a[i][n];
  }
  res = solve(a, l, ans, n, m);
  for (long long i = 0; i < mod; i++) {
    if (f(i) % mod == 0) {
      cout << "! " << i << endl;
      return 0;
    }
  }
  cout << "! " << -1 << endl;
}
