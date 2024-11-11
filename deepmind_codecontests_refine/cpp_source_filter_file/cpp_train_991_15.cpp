#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[100];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (a[0] > 15)
    cout << 15 << endl;
  else
    for (int i = 1; i < n; i++) {
      if (a[i] - a[i - 1] > 15) {
        cout << a[i - 1] + 15 << endl;
        break;
      } else if (i == n - 1 && a[n - 1] <= 75)
        cout << a[i] + 15 << endl;
      else if (i == n - 1 && a[n - 1] > 75)
        cout << 90 << endl;
    }
  return 0;
}
