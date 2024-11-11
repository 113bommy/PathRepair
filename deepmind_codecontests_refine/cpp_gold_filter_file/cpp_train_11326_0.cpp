#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m, a, b;
  cin >> n >> m >> a >> b;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cout << ((i <= b) ^ (j <= a));
    }
    cout << "\n";
  }

  return 0;
}
