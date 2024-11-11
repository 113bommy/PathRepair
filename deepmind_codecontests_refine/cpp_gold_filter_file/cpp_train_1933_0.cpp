#include <bits/stdc++.h>
using namespace std;
int n, m;
long long ai[800], f[800][800];
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> ai[i];
  for (int i = n + 1; i >= 1; --i)
    for (int j = 0; j <= n; ++j) f[i][j] = -1000000000000000LL;
  f[n + 1][0] = 0;
  for (int i = n; i >= 1; --i)
    for (int j = 0; j <= n; ++j)
      f[i][j] = max(min(f[i + 1][j] + ai[i], 0LL),
                    (j ? f[i + 1][j - 1] : -1000000000000000LL));
  for (int i = 1; i <= m; ++i) {
    long long a;
    cin >> a;
    cout << lower_bound(f[1] + 0, f[1] + n + 1, -a) - f[1] << " ";
  }
}
