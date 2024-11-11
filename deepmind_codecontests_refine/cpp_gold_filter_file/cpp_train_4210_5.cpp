#include <bits/stdc++.h>
using namespace std;
class mat {
 public:
  int n, m;
  long long v[85][85];
  mat(int n, int m) : n(n), m(m) {}
  void init() { memset(v, 0, sizeof(v)); }
  void init1() {
    for (int i = 0; i < 85; i++)
      for (int j = 0; j < 85; j++) v[i][j] = (i == j);
  }
  mat operator*(const mat B) const {
    mat C(n, B.m);
    C.init();
    for (int i = 0; i <= n; i++)
      for (int j = 0; j <= B.m; j++)
        for (int k = 0; k <= m; k++)
          C.v[i][j] =
              (C.v[i][j] + v[i][k] * B.v[k][j] % 1000000007) % 1000000007;
    return C;
  }
  mat operator^(long long t) {
    mat ans(n, n), now(n, n);
    ans.init1();
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) now.v[i][j] = v[i][j];
    while (t) {
      if (t & 1) ans = ans * now;
      now = now * now;
      t >>= 1;
    }
    return ans;
  }
};
long long C[85][85];
int main() {
  long long n;
  int k;
  memset(C, 0, sizeof(C));
  C[0][0] = 1;
  for (int i = 1; i <= 82; i++) {
    C[0][i] = C[i][i] = 1;
    for (int j = 1; j <= i; j++) {
      C[j][i] = (C[j][i - 1] + C[j - 1][i - 1]) % 1000000007;
    }
  }
  while (~scanf("%lld%d", &n, &k)) {
    if (n == 1) {
      printf("1\n");
      continue;
    }
    mat ex(2 * k + 3, 2 * k + 3);
    ex.init();
    for (int i = 0; i <= k; i++) {
      for (int j = 0; j <= i; j++) {
        ex.v[i][j] = C[j][i];
      }
    }
    for (int i = 0; i <= k; i++) {
      for (int j = 0; j <= i; j++) {
        ex.v[i + k + 1][j] = C[j][i];
      }
    }
    for (int i = 0; i <= k; i++) {
      for (int j = k + 1; j < 2 * k + 2; j++) {
        ex.v[i][j] = C[j - k - 1][i];
      }
    }
    ex.v[2 * k + 2][k] = 1;
    ex.v[2 * k + 2][2 * k + 2] = 1;
    ex = ex ^ n;
    long long sum = 0;
    for (int i = 0; i < 2 * k + 2; i++) {
      sum = (sum + ex.v[2 * k + 2][i]) % 1000000007;
    }
    printf("%lld\n", sum);
  }
}
