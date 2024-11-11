#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, mx = 0;
  cin >> n;
  int a[n + 3], val[n + 3];
  memset(val, 0, sizeof val);
  for (int i = int(1); i <= int(n); i++) {
    cin >> a[i];
    mx = max(mx, a[i]);
    val[i] = mx + 1;
  }
  for (int i = n - 1; i > 0; i--) {
    if (val[i + 1] - val[i] > 1) val[i] = val[i + 1] - 1;
  }
  int sum = 0;
  for (int i = int(1); i <= int(n); i++) sum += val[i] - a[i] - 1;
  cout << sum;
}
