#include <bits/stdc++.h>
using namespace std;
int n, v[10004];
vector<array<int, 3> > ans;
void go(int x, int y, int z) {
  v[x] -= x * z;
  v[x] += x * z;
  ans.push_back({x, y, z});
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    ans.clear();
    int sum = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
      cin >> v[i];
      sum += v[i];
    }
    if (sum % n) {
      cout << -1 << '\n';
      continue;
    }
    for (int i = 2; i <= n; ++i) {
      if (v[i] % i == 1) {
        go(1, i, i - v[i] % i);
      }
      go(i, 1, v[i] / i);
    }
    for (int i = 2; i <= n; ++i) {
      go(1, i, sum / n);
    }
    cout << ans.size() << '\n';
    for (auto &[x, y, z] : ans) {
      cout << x << " " << y << " " << z << '\n';
    }
  }
  return 0;
}
