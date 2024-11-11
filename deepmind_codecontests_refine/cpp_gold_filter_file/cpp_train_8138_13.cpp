#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1;
long long a[N];
int n, m;
vector<int> e[N];
long long l[N], r[N];
int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  while (cin >> n >> m) {
    for (int i = (1); i < (m + 1); i++) cin >> a[i];
    long long ans = 0;
    for (int i = (1); i < (n + 1); i++) {
      e[i].clear();
      l[i] = r[i] = 0;
    }
    for (int i = (1); i < (m); i++) {
      int x, y;
      x = a[i];
      y = a[i + 1];
      ans += abs(x - y);
      e[x].push_back(y);
      e[y].push_back(x);
      if (x > y) swap(x, y);
      l[x]++;
      r[y]++;
    }
    cout << ans;
    for (int i = (2); i < (n + 1); i++) {
      ans = ans - l[i - 1] + r[i - 1];
      long long tt = ans;
      for (auto v : e[i]) {
        if (v == i) continue;
        if (v < i)
          ans = ans - abs(i - (v + 1)) + abs(1 - (v + 1));
        else
          ans = ans - abs(i - v) + abs(1 - v);
      }
      cout << " " << ans;
      ans = tt;
    }
    cout << '\n';
  }
  return 0;
}
