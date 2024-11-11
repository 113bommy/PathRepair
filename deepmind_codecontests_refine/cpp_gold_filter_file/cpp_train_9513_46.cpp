#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  if (m == 3 && n > 4) {
    puts("-1");
  } else {
    for (int i = 1; i <= m; i++) {
      cout << i << " " << i * (1003 + i) << "\n";
    }
    for (int i = 1; i <= n - m; i++) {
      cout << i << " " << -i * (1092 + i) << "\n";
    }
  }
}
