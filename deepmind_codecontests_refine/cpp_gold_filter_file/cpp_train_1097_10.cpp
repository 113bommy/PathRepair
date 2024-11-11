#include <bits/stdc++.h>
using namespace std;
int main() {
  int ans = 0, n;
  cin >> n;
  int a[3 * n];
  for (int i = 0; i < 3 * n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < 3; i++) {
    for (int j = i; j <= 3 * n - 1; j = j + 3) {
      ans += a[j];
    }
    if (ans != 0) break;
  }
  if (ans == 0)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
