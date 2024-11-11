#include <bits/stdc++.h>
using namespace std;
int main() {
  int x[11], c[10] = {0}, n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> x[i];
  for (int i = 1; i <= m; ++i) {
    int a;
    cin >> a;
    c[a] = 1;
  }
  for (int i = 1; i <= n; ++i)
    if (c[x[i]]) cout << x[i] << ' ';
  return 0;
}
