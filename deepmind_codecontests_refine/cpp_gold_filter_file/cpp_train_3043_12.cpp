#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, d;
    cin >> n >> d;
    int N = n - 1;
    int de = 0, q = 1, l = 0;
    while (N) {
      q *= 2;
      de++;
      int f = min(N, q);
      N -= f;
      l += f * de;
    }
    if (l > d) {
      cout << "NO\n";
      continue;
    }
    int cur = (n * (n - 1)) / 2;
    vector<int> par(n + 1, 1), hit_plateau(n + 1, 0), cont(n + 1, 0),
        depth(n + 1, 0);
    for (int i = 2; i <= n; i++) {
      par[i] = i - 1;
      cont[i - 1] = 1;
      depth[i] = depth[i - 1] + 1;
    }
    while (cur > d) {
      int v = -1;
      for (int i = 2; i <= n; i++) {
        if (cont[i] == 0 and !hit_plateau[i]) {
          if (v == -1) {
            v = i;
          } else if (depth[i] < depth[v]) {
            v = i;
          }
        }
      }
      if (v == -1) break;
      int p = -1;
      for (int i = 1; i <= n; i++) {
        if (cont[i] < 2 and depth[i] == depth[v] - 2) {
          p = i;
        }
      }
      if (p == -1) {
        hit_plateau[v] = 1;
        continue;
      }
      cont[par[v]]--;
      par[v] = p;
      depth[v]--;
      cont[p]++;
      cur--;
    }
    if (cur != d)
      cout << "NO\n";
    else {
      cout << "YES\n";
      for (int i = 2; i <= n; i++) {
        cout << par[i] << " ";
      }
      cout << "\n";
    }
  }
}
