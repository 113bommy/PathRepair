#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int a[n];
  int b[n];
  bool found = false;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 1; i <= n / 3; i++) {
    if (n % i != 0) continue;
    for (int j = 0; j < n; j++) {
      if (j < i)
        b[j] = a[j];
      else
        b[j] = a[j] + b[j - i];
      if (b[j] == n / i) {
        found = true;
      }
    }
    if (found) break;
  }
  if (found)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
