#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, v;
  cin >> n >> m >> v;
  v--;
  int vv = v + 1;
  vv %= n;
  if (m > ((n - 1) * (n - 2) / 2 + 1) || m < n - 1)
    cout << -1;
  else {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (i != v && cnt < m) {
        printf("%d %d\n", i + 1, v + 1);
        cnt++;
      }
    }
    if (cnt == m) return 0;
    for (int i = 0; i < n; i++) {
      if (cnt == m) break;
      for (int j = i + 1; j < n; j++) {
        if (cnt == m) break;
        if (cnt < m && i != v && j != v && i != vv && j != vv) {
          printf("%d %d\n", i + 1, j + 1);
          cnt++;
        }
        if (cnt == m) break;
      }
      if (cnt == m) break;
    }
  }
  return 0;
}
