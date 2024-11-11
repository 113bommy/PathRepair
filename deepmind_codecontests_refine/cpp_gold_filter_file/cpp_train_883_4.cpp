#include <bits/stdc++.h>
using namespace std;
int path[410][410];
int la[410];
int lb[410];
int main() {
  int n, m;
  while (cin >> n >> m) {
    int a, b;
    for (int i = 0; i < m; i++) {
      cin >> a >> b;
      path[a][b] = 1;
      path[b][a] = 1;
    }
    for (int i = 1; i <= n; i++) {
      if (path[1][i]) {
        la[i] = 1;
        lb[i] = n + 1;
      } else {
        la[i] = n + 1;
        lb[i] = 1;
      }
    }
    for (int l = 2; l <= n; l++) {
      for (int end = 1; end <= n; end++) {
        for (int mid = 1; mid <= n; mid++) {
          if (la[mid] == n + 1 || !path[mid][end]) continue;
          la[end] = min(la[end], la[mid] + 1);
        }
      }
      if (la[n] != n + 1) break;
    }
    for (int l = 2; l <= n; l++) {
      for (int end = 1; end <= n; end++) {
        for (int mid = 1; mid <= n; mid++) {
          if (lb[mid] == n + 1 || path[mid][end]) continue;
          lb[end] = min(lb[end], lb[mid] + 1);
        }
      }
      if (lb[n] != n + 1) break;
    }
    if (la[n] == n + 1 || lb[n] == n + 1)
      cout << -1 << endl;
    else
      cout << max(la[n], lb[n]) << endl;
  }
  return 0;
}
