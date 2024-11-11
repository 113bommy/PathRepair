#include <bits/stdc++.h>
using namespace std;
int a[120], n, t;
bool check();
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    if (check())
      cout << "YES";
    else
      cout << "NO";
  }
}
bool check() {
  for (int i = 1; i < n; i++) {
    if (a[i + 1] == a[i] || a[i + 1] == a[i] + 1)
      continue;
    else
      return false;
  }
  return true;
}
