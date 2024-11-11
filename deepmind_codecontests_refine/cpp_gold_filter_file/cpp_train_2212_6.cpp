#include <bits/stdc++.h>
using namespace std;
int main() {
  int x;
  cin >> x;
  while (x--) {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int flag = 0;
    int e = 0, o = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] % 2 == 0) {
        e++;
      } else {
        o++;
      }
    }
    if (e % 2 == 0) {
      cout << "YES\n";
      continue;
    }
    sort(a, a + n);
    for (int i = 0; i < n - 1; i++) {
      if (a[i + 1] - a[i] == 1) {
        cout << "YES\n";
        flag = 1;
        break;
      }
    }
    if (flag == 0) {
      cout << "NO\n";
    }
  }
  return 0;
}
