#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, flag = 0;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  for (int i = 0; i < n - 3; i++) {
    if ((a[i + 1] == a[i] + 1)) {
      for (int j = i + 1; j < n - 1; j++) {
        if (a[j + 1] - 1 == a[i + 1]) {
          flag = 1;
          break;
        }
      }
    }
  }
  if (flag == 1)
    cout << "YES\n";
  else
    cout << "NO\n";
  return 0;
}
