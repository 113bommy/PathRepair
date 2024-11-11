#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  vector<int> f(5001), g(5001);
  for (int i = 1; i <= 5000; i++) {
    f[i] = g[i] = (i - 1) * i / 2;
    for (int j = 0; j < i; j++) {
      f[i] = min(f[i], f[j] + f[i - j - 1] + i - 1);
    }
  }
  while (T--) {
    int n, D;
    cin >> n >> D;
    if (D < f[n] || D > g[n]) {
      cout << "NO" << endl;
      continue;
    }
    vector<int> pre(n + 1);
    function<void(int, int, int, int)> solve = [&](int l, int r, int fa,
                                                   int sum) {
      if (l > r) return;
      pre[l] = fa;
      int z = r - l + 1;
      assert(f[z] <= sum && g[z] >= sum);
      sum -= (z - 1);
      for (int i = 0; i < z; i++) {
        if (f[z - i - 1] <= sum - f[i] && g[z - i - 1] >= sum - f[i]) {
          solve(l + 1, l + i, l, f[i]);
          solve(l + i + 1, r, l, sum - f[i]);
          break;
        } else if (f[z - i - 1] <= sum - g[i] && g[z - i - 1] >= sum - g[i]) {
          solve(l + 1, l + i, l, g[i]);
          solve(l + i + 1, r, l, sum - g[i]);
          break;
        }
      }
    };
    cout << "YES" << endl;
    solve(1, n, 0, D);
    for (int i = 2; i <= n; i++) {
      assert(pre[i]);
      cout << pre[i] << " ";
    }
    cout << endl;
  }
  return 0;
}
