#include <bits/stdc++.h>
using namespace std;
int n, m;
int main() {
  cin >> n >> m;
  for (int to = 1, i = 1, j = 2 * n + 1; to <= n; to++, i += 2, j += 2) {
    if (j <= m) {
      cout << j << ' ';
    }
    if (i <= m) {
      cout << i << ' ';
    }
    if (j + 1 <= m) {
      cout << j + 1 << ' ';
    }
    if (i + 1 <= m) {
      cout << i + 1 << ' ';
    }
  }
  return 0;
}
