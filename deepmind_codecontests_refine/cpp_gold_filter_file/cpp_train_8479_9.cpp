#include <bits/stdc++.h>
using namespace std;
int vis[100000 + 10];
int main() {
  int n, k;
  cin >> n >> k;
  memset(vis, 0, sizeof(vis));
  for (int i = 1; i <= n; ++i) {
    if (k != 0 && vis[i] == 0 && vis[i + k] == 0) {
      vis[i] = 1;
      vis[i + k] = 1;
      cout << i << " " << i + k << " ";
      k -= 2;
    } else if (vis[i] == 0) {
      vis[i] = 1;
      cout << i << " ";
    }
  }
  return 0;
}
