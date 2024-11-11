#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool d[101010];
bool p[101010];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) d[i] = 0;
    for (int i = 1; i <= n; ++i) p[i] = 0;
    for (int i = 1; i <= n; ++i) {
      int m;
      cin >> m;
      for (int j = 1; j <= m; ++j) {
        int x;
        cin >> x;
        if (d[i] || p[x]) continue;
        d[i] = 1;
        p[x] = 1;
      }
    }
    int a = 0, b = 0;
    for (int i = 1; i <= n; ++i) {
      if (!d[i]) a = i;
      if (!p[i]) b = i;
    }
    if (a && b) {
      cout << "IMPROVE\n";
      cout << a << " " << b << '\n';
    } else
      cout << "OPTIMAL\n";
  }
}
