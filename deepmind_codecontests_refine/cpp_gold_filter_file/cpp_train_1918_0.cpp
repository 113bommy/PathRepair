#include <bits/stdc++.h>
using namespace std;
long long int solve(long long int n, long long int m, long long int i,
                    long long int j, long long int a, long long int b,
                    long long int c1, long long int c2) {
  if ((i - c1) % a == 0 && (j - c2) % b == 0) {
    long long int x = abs((i - c1) / a);
    long long int y = abs((j - c2) / b);
    if ((x - y) % 2 == 0) {
      if (x == y)
        return x;
      else if (x > y) {
        if (j + b <= m || j - b > 0) return x;
      } else {
        if (i + a <= n || i - a > 0) return y;
      }
    }
  }
  return 1000000007;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int n, m, i, j, a, b;
  cin >> n >> m >> i >> j >> a >> b;
  long long int c1 = solve(n, m, i, j, a, b, 1, 1);
  long long int c2 = solve(n, m, i, j, a, b, n, 1);
  long long int c3 = solve(n, m, i, j, a, b, 1, m);
  long long int c4 = solve(n, m, i, j, a, b, n, m);
  long long int max = fmin(c1, fmin(c2, fmin(c3, c4)));
  if (max == 1000000007) {
    cout << "Poor Inna and pony!";
  } else {
    cout << max;
  }
}
