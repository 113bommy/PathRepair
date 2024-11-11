#include <bits/stdc++.h>
using namespace std;
long long a, b, c, n, t, v[100], p[100][100], ans, sum, B;
void dfsb(long long now, long long A, long long V) {
  if ((double)A * V * V > sum) {
    return;
  }
  if (now > n) {
    B = max(B, V);
    return;
  }
  for (long long i = v[now]; i >= 0; --i) {
    dfsb(now + 1, A, V * p[now][i]);
  }
}
void dfsa(long long now, long long A) {
  if ((double)A * A * A > sum) {
    return;
  }
  if (now > n) {
    long long l = 4 * A * sqrt(sum / A) + 2 * sum / A;
    if (l < ans) {
      B = 0;
      dfsb(1, A, 1);
      long long C = sum / A / B, S = 2 * (A * B + A * C + B * C);
      if (S < ans) {
        ans = S;
        a = A;
        b = B;
        c = C;
      }
    }
    return;
  }
  for (long long i = v[now]; i >= 0; --i) {
    v[now] -= i;
    dfsa(now + 1, A * p[now][i]);
    v[now] += i;
  }
}
signed main() {
  std::ios::sync_with_stdio(false);
  cin >> t;
  while (t--) {
    cin >> n;
    sum = 1;
    for (long long i = 1; i <= n; ++i) {
      cin >> a >> b;
      v[i] = b;
      p[i][0] = 1;
      for (long long j = 1; j <= b; ++j) {
        p[i][j] = p[i][j - 1] * a;
      }
      sum *= p[i][b];
    }
    ans = 0x3fffffffffffffff;
    dfsa(1, 1);
    cout << ans << ' ' << a << ' ' << b << ' ' << c << endl;
  }
  return 0;
}
