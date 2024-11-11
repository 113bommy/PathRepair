#include <bits/stdc++.h>
using namespace std;
const int N = 100 + 5;
int m, n, res, a[N][N], best[N];
string s;
void Input() {
  cin >> m >> n;
  for (int i = 1; i <= m; i++) {
    cin >> s;
    for (int j = 0; j < s.size(); j++) a[i][j + 1] = s[i] - 48;
  }
}
void Solve() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) best[i] = max(best[i], a[i][j]);
  }
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      if (a[i][j] == best[j]) {
        res++;
        break;
      }
    }
  }
  cout << res << '\n';
}
int main() {
  Input();
  Solve();
  return 0;
}
