#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
int vis[4444444];
int a[111111];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    vis[a[i]] = a[i];
  }
  int e = (1 << 22) - 1;
  for (int i = 1; i <= e; ++i) {
    for (int j = 0; j < 22; ++j) {
      if ((i & (1 << j)) && vis[i - (1 << j)]) {
        vis[i] = vis[i - (1 << j)];
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (vis[e ^ a[i]])
      cout << vis[e ^ a[i]];
    else
      cout << -1;
    cout << ' ';
  }
  cout << endl;
  return 0;
}
