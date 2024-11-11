#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, i = 0, c = 0;
  cin >> t;
  for (; i < t; i++) {
    c = 0;
    int n;
    cin >> n;
    int a[n];
    for (int j = 0; j < n; j++) {
      cin >> a[j];
    }
    if (a[0] == 1) c++;
    for (int k = 1; k < n; k++) {
      if (a[k] == 1 && a[k - 1] == 0)
        c++;
      else if (a[k] == 1 && a[k - 1] == 1)
        c = c + 5;
      else if (a[k] == 0 && a[k - 1] == 1)
        ;
      else if (a[k] == 0 && a[k - 1] == 0) {
        c = -1;
        break;
      }
    }
    cout << c << endl;
  }
}
