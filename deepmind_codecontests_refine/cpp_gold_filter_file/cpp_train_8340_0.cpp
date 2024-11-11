#include <bits/stdc++.h>
using namespace std;
int main() {
  ios ::sync_with_stdio(false);
  cin.tie(0);
  long long int n, i, t, j = 0, x, y, k, c = 0, b;
  cin >> n;
  long long int a[n + 1];
  for (i = 1; i * 2 <= n; i++) {
    cin >> b;
    if (i == 1)
      a[i] = 0;
    else
      a[i] = max(a[i - 1], b - a[n - i + 2]);
    a[n - i + 1] = b - a[i];
  }
  cout << 0 << " ";
  for (i = 2; i <= n; i++) {
    cout << a[i] << " ";
  }
}
