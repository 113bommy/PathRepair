#include <bits/stdc++.h>
using namespace std;
const int INF = 20050208;
int col[1005];
int main() {
  int n, m;
  cin >> n >> m;
  int ans = 0;
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    col[x]++;
    bool ok = true;
    for (int j = 1; j <= n; j++) {
      if (col[i] == 0) {
        ok = false;
      }
    }
    if (ok) {
      ans++;
      for (int j = 1; j <= n; j++) {
        col[j]--;
      }
    }
  }
  cout << ans;
  return 0;
}
