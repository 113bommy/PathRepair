#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[]) {
  int n, m;
  int x[1005], y[1005];
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    x[i] = 0;
    y[i] = 0;
  }
  x[1] = 1;
  x[n] = 1;
  y[1] = 1;
  y[n] = 1;
  int a, b;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    x[a] = 1;
    y[b] = 1;
  }
  int ans = (n - 2) * 2 - (n % 2);
  int k = n / 2 + n % 2;
  for (int i = 2; i < n; i++) {
    if (x[i] == 1) {
      if (i == k && n % 2 == 1)
        ans;
      else
        ans--;
    }
    if (y[i] == 1) {
      if (i == k && n % 2 == 1)
        ans;
      else
        ans--;
    }
  }
  if (x[k] == 1 && y[k] == 1 && n > 2) ans--;
  cout << ans;
  return EXIT_SUCCESS;
}
