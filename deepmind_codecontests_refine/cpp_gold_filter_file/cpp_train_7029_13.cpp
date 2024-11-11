#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 7;
int n;
char a[maxn][10];
void input() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= 6; ++j) cin >> a[i][j];
}
void proc() {
  int res = 6;
  for (int i = 1; i < n; ++i)
    for (int j = i + 1; j <= n; ++j) {
      int cur = 0;
      for (int k = 1; k <= 6; ++k) cur += (a[i][k] != a[j][k]);
      res = min(res, (cur >> 1) + (cur & 1) - 1);
    }
  cout << res;
}
int main() {
  input();
  proc();
  return 0;
}
