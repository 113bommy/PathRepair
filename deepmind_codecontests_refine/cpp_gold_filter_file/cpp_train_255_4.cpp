#include <bits/stdc++.h>
using namespace std;
using namespace std;
const int N = 20;
const int len = 300;
string s[N];
int c[N][len], sv[N][len], a[N][len];
int d[1 << N];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> s[i];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> a[i][j];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      int curv = 0;
      for (int k = 0; k < n; k++)
        if (s[i][j] == s[k][j]) {
          sv[i][j] |= (1 << k);
          c[i][j] += a[k][j];
          if (a[k][j] > curv) curv = a[k][j];
        }
      c[i][j] -= curv;
    }
  for (int i = 0; i < 1 << n; i++) d[i] = 1000000000;
  d[0] = 0;
  for (int mask = 0; mask < 1 << n; mask++) {
    if (mask == 0) continue;
    int lowbit = -1;
    for (int i = 0; i < n; i++)
      if ((mask >> i) & 1) {
        lowbit = i;
        break;
      }
    for (int k = 0; k < m; k++) {
      d[mask] = min(d[mask], d[mask & (mask ^ sv[lowbit][k])] + c[lowbit][k]);
      d[mask] = min(d[mask], d[mask ^ (1 << lowbit)] + a[lowbit][k]);
    }
  }
  cout << d[(1 << n) - 1];
  return 0;
}
