#include <bits/stdc++.h>
using namespace std;
int n, id = 0, mn = 0;
int a[1000010];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  bool ok = false;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (n % 2 == 0) {
      cout << min(a[i], -a[i] - 1) << " ";
    }
    if (a[i] && a[i] + 1) ok = true;
    a[i] = max(a[i], -a[i] - 1);
    if (a[i] > mn && a[i] > 0) mn = a[i], id = i;
  }
  if (n % 2 == 0) return 0;
  if (!ok) {
    for (int i = 1; i <= n; i++) cout << "0 ";
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    if (i == id)
      continue;
    else
      a[i] = min(a[i], -a[i] - 1);
  }
  for (int i = 1; i <= n; i++) {
    cout << a[i] << " ";
  }
  return 0;
}
