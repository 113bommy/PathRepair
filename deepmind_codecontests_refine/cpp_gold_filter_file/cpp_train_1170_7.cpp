#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int n, x, y, m, tmp, ans, t, white;
char a[N][N];
string s, p;
bool mark[N];
void read_input() {
  ans = 0;
  white = 0;
  cin >> n >> m >> x >> y;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      if (a[i][j] == '.') white++;
    }
  }
}
void solve() {
  if (2 * x <= y) {
    cout << white * x << '\n';
  } else {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (a[i][j] == '.') {
          if (a[i][j + 1] == '.') {
            ans += y;
            j++;
          } else
            ans += x;
        }
      }
    }
    cout << ans << '\n';
  }
}
int main() {
  cin >> t;
  while (t--) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        a[i][j] = 0;
      }
    }
    read_input();
    solve();
  }
  return 0;
}
