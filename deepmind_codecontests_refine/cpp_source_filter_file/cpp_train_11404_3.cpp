#include <bits/stdc++.h>
using namespace std;
int n, t, ans;
double a[100][100];
void f(int x, int y, double t) {
  if (t <= 0 || y > n) return;
  double d = min(a[x][y], t);
  t -= d;
  a[x][y] -= d;
  f(x + 1, y, t / 2.0);
  f(x + 1, y + 1, t / 2.0);
}
int main() {
  cin >> n >> t;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= i; ++j) a[i][j] = 1;
  f(1, 1, t);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= i; ++j)
      if (a[i][j] == 0) ans++;
  cout << ans << endl;
}
