#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int n;
char c[N][N];
char f(char c) { return (c == 'w' ? 'b' : 'w'); }
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  if (n & 1) {
    cout << -1;
    return 0;
  } else {
    int l = 0, r = n - 1, u = 0, d = n - 1;
    for (int i = 0; i < (n >> 1); i++) {
      for (int j = l; j <= r; j++) c[u][j] = c[d][j] = (i & 1 ? 'w' : 'b');
      for (int j = u; j <= d; j++) c[j][l] = c[j][r] = (i & 1 ? 'w' : 'b');
      l++;
      r--;
      u++;
      d--;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++, cout << '\n')
      for (int k = 0; k < n; k++) cout << (i & 1 ? c[j][k] : f(c[j][k]));
    cout << '\n';
  }
  return 0;
}
