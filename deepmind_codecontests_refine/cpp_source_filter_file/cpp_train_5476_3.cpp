#include <bits/stdc++.h>
using namespace std;
int const inf = 1000 * 1000 * 1000;
long long const inf64 = 1ll * inf * inf;
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n + 1, -1);
  vector<int> l(m);
  for (int i = 0; i < m; i++) {
    cin >> l[i];
  }
  for (int i = 0; i + 1 < m; i++) {
    int cur = -1;
    for (int x = 1; x <= n; x++) {
      int nx = (l[i] + x) % n + 1;
      if (l[i + 1] == nx) {
        cur = x;
        break;
      }
    }
    if (cur == -1) {
      cout << "-1\n";
      return 0;
    }
    if (a[l[i]] != -1 && a[l[i]] != cur) {
      cout << "-1\n";
      return 0;
    }
    a[l[i]] = cur;
  }
  vector<char> used(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    if (a[i] == -1) continue;
    if (used[a[i]]) {
      cout << "-1\n";
      return 0;
    } else {
      used[a[i]] = 1;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (a[i] == -1) {
      for (int j = 1; j <= n; j++) {
        if (!used[j]) {
          used[j] = 1;
          a[i] = j;
          break;
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << a[i] << " ";
  }
  cout << "\n";
  return 0;
}
