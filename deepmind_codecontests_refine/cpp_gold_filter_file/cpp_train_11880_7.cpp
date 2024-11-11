#include <bits/stdc++.h>
using namespace std;
int n, path[200010], cnt = 0, fa[200010];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 2; i <= n; ++i) {
    cin >> fa[i];
  }
  path[cnt++] = n;
  while (path[cnt - 1] != 1) {
    path[cnt] = fa[path[cnt - 1]];
    ++cnt;
  }
  for (int i = cnt - 1; i >= 0; --i) {
    cout << path[i] << ' ';
  }
  return 0;
}
