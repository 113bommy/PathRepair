#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int a[N], n, p, K, f[2][N], mx[105], l[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> K >> p;
  for (int i = 1; i <= n; ++i) cin >> a[i], a[i] += a[i - 1], a[i] %= p;
  memset(f, 69, sizeof f);
  if (n <= K * p) {
    f[0][0] = 0;
    for (int j = 1; j <= K; ++j) {
      memset(mx, 69, sizeof mx);
      memset(f[1], 69, sizeof f[1]);
      for (int i = 1; i <= n; ++i) {
        mx[a[i - 1]] = min(mx[a[i - 1]], f[0][i - 1]);
        for (int k = 0; k < p; ++k)
          f[1][i] = min(f[1][i], k + mx[(a[i] - k + p) % p]);
      }
      swap(f[0], f[1]);
    }
    cout << f[0][n];
  } else {
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j <= a[i]; ++j) l[i] = max(l[i], mx[j] + 1);
      mx[a[i]] = max(mx[a[i]], l[i]);
    }
    if (l[n] >= K)
      cout << a[n];
    else
      cout << a[n] + p;
  }
}
