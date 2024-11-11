#include <bits/stdc++.h>
using namespace std;
long long a[9];
long long dfs(long long vis, long long w) {
  if (vis > 8) return w;
  long long res = min(a[vis], w / vis), mins = 1e18;
  for (long long i = res; i >= max(res - 8 / vis - 2, (long long)0); i--) {
    mins = min(mins, dfs(vis + 1, w - i * vis));
  }
  return mins;
}
int main() {
  long long w;
  while (cin >> w) {
    for (long long i = 1; i <= 8; i++) cin >> a[i];
    cout << w - dfs(1, w) << endl;
  }
}
