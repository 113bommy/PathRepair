#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<int> v(n + 1, 0);
    int i;
    for (int i = 0; i < m; i++) {
      int a, b, c;
      cin >> a >> b >> c;
      v[b] = 1;
    }
    for (i = 1; i <= n; i++)
      if (!v[i]) break;
    for (int j = 1; j <= n; j++)
      if (i != j) cout << i << " " << j << endl;
  }
  return 0;
}
