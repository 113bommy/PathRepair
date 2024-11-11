#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int n, m;
int a[11][maxn], pos[11][maxn], L[11];
void Input() {
  cin >> n >> m;
  for (int i = (1); i <= (m); ++i) {
    for (int j = (1); j <= (n); ++j) {
      cin >> a[i][j];
      pos[i][a[i][j]] = j;
    }
  }
}
void Solve() {
  int i = 1;
  long long res = 0;
  while (i <= n) {
    for (int j = (1); j <= (m); ++j) L[j] = pos[j][a[1][i]];
    int last = i;
    while (i < n) {
      bool bl = true;
      for (int j = (1); j <= (m); ++j)
        if (a[j][++L[j]] != a[1][i + 1]) {
          bl = false;
          break;
        }
      if (bl)
        ++i;
      else
        break;
    }
    ++i;
    long long len = i - last;
    res += len * (len + 1) / 2;
  }
  cout << res;
}
int main() {
  iostream::sync_with_stdio(false);
  cin.tie(0);
  Input();
  Solve();
  return 0;
}
