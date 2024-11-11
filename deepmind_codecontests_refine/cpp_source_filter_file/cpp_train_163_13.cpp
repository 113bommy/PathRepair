#include <bits/stdc++.h>
using namespace std;
int n, m, p, v[1000005], u[1000005];
long long r = 1e18;
int main() {
  cin >> n >> m >> p;
  for (int i = 1; i <= n; i++) cin >> v[i];
  for (int i = 1; i <= m; i++) cin >> u[i];
  sort(v + 1, v + n + 1);
  sort(u + 1, u + n + 1);
  for (int i = 1; i <= m - n + 1; i++) {
    long long s = 0;
    for (int j = 1; j <= n; j++) {
      int k = i + j - 1;
      s = max(s, 1ll * abs(u[k] - v[j]) + abs(p - u[k]));
    }
    r = min(r, s);
  }
  cout << r;
}
