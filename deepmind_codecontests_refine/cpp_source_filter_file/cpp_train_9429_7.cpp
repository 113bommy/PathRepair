#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  bool b = false;
  for (int i = 2; i < n; i++) {
    if (a[i - 2] + a[i - 1] < a[i] && a[i] + a[i - 1] < a[i - 2] &&
        a[i - 2] + a[i] < a[i - 1]) {
      b = true;
      break;
    }
  }
  cout << (b ? "YES" : "NO") << endl;
  return 0;
}
