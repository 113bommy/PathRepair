#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a[10009], i;
  cin >> n;
  for (i = 0; i < 2 * n; i++) {
    cin >> a[i];
  }
  sort(a, a + 2 * n);
  if (a[n - 1] == a[n])
    cout << "YES\n";
  else
    cout << "NO\n";
  return 0;
}
