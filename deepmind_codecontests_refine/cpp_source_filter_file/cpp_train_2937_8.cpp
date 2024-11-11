#include <bits/stdc++.h>
using namespace std;
const int N = 5 * 1e2 + 5;
int g[N][N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int r, c;
  cin >> r >> c;
  if (r == 1 && c == 1)
    cout << 0 << '\n';
  else if (r == 1) {
    for (int i = 1; i <= c; i++) {
      cout << i << " ";
    }
    cout << '\n';
  } else if (c == 1) {
    for (int i = 1; i <= r; i++) {
      cout << i << '\n';
    }
  } else {
    for (int i = 1; i <= r; i++) g[i][1] = i + 1;
    for (int i = 2; i <= c; i++) {
      for (int j = 1; j <= r; j++) {
        g[j][i] = (r + i) * g[j][1];
      }
    }
    for (int i = 1; i <= r; i++) {
      for (int j = 1; j <= c; j++) {
        cout << g[i][j] << " ";
      }
      cout << '\n';
    }
  }
  return 0;
}
