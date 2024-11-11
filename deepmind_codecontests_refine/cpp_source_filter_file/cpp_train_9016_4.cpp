#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> a[100000];
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    int alpha;
    cin >> alpha;
    int mod = alpha % k;
    a[mod].push_back(alpha);
  }
  bool f = false;
  for (int i = 0; i < 100000; i++)
    if (a[i].size() >= m) {
      cout << "YES\n";
      for (int j = 0; j < m; j++) cout << a[i][j] << " ";
      f = true;
      cout << '\n';
      break;
    }
  if (!f) cout << "NO\n";
}
