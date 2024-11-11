#include <bits/stdc++.h>
using namespace std;
using ii = long long;
const int N = 1 << 20;
int d[N];
int main() {
  int n;
  ii k;
  cin >> n >> k;
  if (k < 1ll * n * (n + 1) / 2) {
    cout << -1 << "\n";
    return 0;
  }
  cout << min(k, 1ll * n * (n + 1) / 2 + 1ll * n * n / 4) << "\n";
  for (int i = 1; i <= n; ++i) {
    cout << i << " ";
  }
  cout << "\n";
  auto check = [&](int x) -> ii {
    ii r = 0;
    int o = 1;
    for (int i = 1; i <= x; ++i) {
      r += max(o++, n - i + 1);
    }
    for (int i = x + 1; i <= n; ++i) {
      r += max(o++, x - i);
    }
    return r;
  };
  int z = 0;
  for (int b = 1 << 19; b; b /= 2) {
    if (z + b <= n && check(b + z) <= k) z += b;
  }
  for (int i = 1; i <= z; ++i) {
    d[i] = n - i + 1;
  }
  for (int i = z + 1; i <= n; ++i) {
    d[i] = i - z;
  }
  auto check2 = [&](int x) -> ii {
    int it = 1;
    int r = 0;
    for (int i = 1; i <= n; ++i) {
      int y;
      if (i == n - x) {
        y = d[n];
      } else
        y = d[it++];
      r += max(y, i);
    }
    return r;
  };
  int g = 0;
  for (int b = 1 << 19; b; b /= 2) {
    if (b + g <= n - z && check2(b + g) <= k) g += b;
  }
  int it = 1;
  for (int i = 1; i <= n; ++i) {
    if (i == n - g) {
      cout << d[n] << " ";
    } else
      cout << d[it++] << " ";
  }
  cout << "\n";
}
