#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k = 0, l = 0;
  char a[120];
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) {
    if (a[i] == 'B')
      k++;
    else {
      if (k > 0) {
        l++;
        k = 0;
      }
    }
  }
  if (a[n - 1] == 'B') l++;
  cout << l << endl;
  int t = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == 'B') t++;
    if (a[i] == 'B' && i == n - 1)
      cout << t << endl;
    else {
      if (a[i] == 'W') {
        if (t != 0) {
          if (i < n - 1)
            cout << t << " ";
          else
            cout << t << endl;
        }
        t = 0;
      }
    }
  }
  return 0;
}
