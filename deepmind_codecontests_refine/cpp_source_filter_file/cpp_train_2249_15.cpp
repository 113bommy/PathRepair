#include <bits/stdc++.h>
using namespace std;
char t[105][105];
int main() {
  int n, m;
  cin >> n >> m;
  int l = m + 1, r = 0, u = n + 1, d = 0, tmp;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> t[i][j];
      if (t[i][j] == 'B') {
        l = min(l, j);
        r = max(r, j);
        u = min(u, i);
        d = max(d, i);
        tmp++;
      }
    }
  }
  if (tmp == 0)
    cout << '1' << endl;
  else {
    int k = max(r - l + 1, d - u + 1);
    if (n < k || m < k)
      cout << "-1" << endl;
    else
      cout << k * k - tmp << endl;
  }
}
