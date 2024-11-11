#include <bits/stdc++.h>
using namespace std;
int a[10009];
bool vis[10009];
int main() {
  int n, mi = INT_MAX;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    mi = min(mi, a[i]);
  }
  sort(a + 1, a + n + 1);
  int res = 0;
  vis[a[1]] = true;
  for (int i = 2; i <= n; i++) {
    int x = a[i];
    while (vis[x]) {
      x++;
      res++;
    }
    vis[x] = true;
  }
  cout << res << endl;
  return 0;
}
