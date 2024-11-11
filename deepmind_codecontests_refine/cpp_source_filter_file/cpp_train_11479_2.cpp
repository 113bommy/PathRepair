#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int a[10005];
  cin >> n;
  bool special = true;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] != 1) special = false;
  }
  sort(a, a + n);
  if (!special) {
    cout << "1";
    for (int i = 0; i < n - 1; i++) cout << " " << a[i];
  } else {
    if (n > 1) {
      cout << "1";
      for (int i = 1; i < n - 1; i++) cout << " " << a[i];
      cout << " 2";
    } else
      cout << "2";
  }
  cout << endl;
  return 0;
}
