#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k, u;
  int t[2005];
  char c;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> c;
      if (c == 'R') {
        u = i - 1 + j;
        if (u <= m && u > 0) t[u]++;
      } else if (c == 'L') {
        u = j - i + 1;
        if (u <= m && u > 0) t[u]++;
      } else if (c == 'U') {
        if (i % 2 != 0) t[j]++;
      }
    }
  }
  for (int i = 1; i <= m; i++) cout << t[i] << " ";
  return 0;
}
