#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<bool> x;
  vector<bool> y;
  x.assign(n + 1, 1);
  y.assign(n + 1, 1);
  x[1] = 0;
  y[1] = 0;
  x[n] = 0;
  y[n] = 0;
  for (int i = 0; i < m; i++) {
    int tmp_x, tmp_y;
    scanf("%i %i", &tmp_x, &tmp_y);
    x[tmp_x] = 0;
    y[tmp_y] = 0;
  }
  int result = 0;
  for (int i = 1; i <= n / 2; i++) {
    if (i * 2 != n + 1) {
      if (x[i] == 1) result++;
      if (x[n - i + 1] == 1) result++;
      if (y[i] == 1) result++;
      if (y[n - i + 1] == 1) result++;
    }
  }
  if (n % 2 == 1)
    if ((x[n / 2 + 1] == 1) || (y[n / 2 + 1] == 1)) result++;
  cout << result << endl;
  return 0;
}
