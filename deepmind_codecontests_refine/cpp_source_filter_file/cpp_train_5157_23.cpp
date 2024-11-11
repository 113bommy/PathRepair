#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  cin >> n;
  int y[n + 1], x[n + 1], a[n + 1];
  for (int i = 0; i <= n; i++) {
    cin >> x[i] >> y[i];
  }
  for (int i = 1; i <= n; i++) {
    if (x[i] > x[i - 1])
      a[i] = 1;
    else if (x[i] < x[i - 1])
      a[i] = 2;
    else if (y[i] > y[i - 1])
      a[i] = 3;
    else if (y[i] < y[i - 1])
      a[i] = 4;
  }
  int ans = 0;
  for (int i = 2; i <= n; i++) {
    if (a[i - 1] == 1 && a[i] == 3)
      ans++;
    else if (a[i - 1] == 2 && a[i] == 3)
      ans++;
    else if (a[i - 1] == 3 && a[i] == 2)
      ans++;
    else if (a[i - 1] == 4 && a[i] == 1)
      ans++;
  }
  cout << ans << "\n";
}
