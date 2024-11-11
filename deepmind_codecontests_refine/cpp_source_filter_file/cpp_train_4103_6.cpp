#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  int row[1000];
  for (int i = 0; i < 100; i++) {
    row[i] = 2000000;
  }
  int v, u;
  for (int i = 0; i < n; i++) {
    cin >> u >> v;
    row[u - 1] = min(row[u - 1], v);
  }
  int tot = 0;
  for (int i = 0; i < m; i++) {
    tot += row[i];
  }
  cout << min(tot, k) << endl;
  return 0;
}
