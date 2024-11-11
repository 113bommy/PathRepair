#include <bits/stdc++.h>
using namespace std;
long long ot = 0, n, m, h[1005], w[1005];
char a[1005][1005];
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
      if (a[i][j] == '*') {
        ++h[i];
        ++w[j];
      }
    }
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (a[i][j] == '*' && (h[i] - 1) * (w[j] - 1) > 0) {
        ot += (h[i] - 1) * (w[j] - 1);
      }
  cout << ot;
  return 0;
}
