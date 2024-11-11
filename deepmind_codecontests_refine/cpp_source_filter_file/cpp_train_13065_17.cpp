#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int ans;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int a, b;
      cin >> a >> b;
      if (a || b) ans++;
    }
  }
  cout << ans;
  return 0;
}
