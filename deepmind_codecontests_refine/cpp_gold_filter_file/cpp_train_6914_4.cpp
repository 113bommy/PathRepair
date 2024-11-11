#include <bits/stdc++.h>
using namespace std;
int a[301];
int main() {
  int n;
  cin >> n;
  int m = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] > m) m = a[i];
  }
  for (int j = 0; j < m; j++) {
    for (int i = 0; i < n - 1; i++) {
      if (a[i] > 0) {
        cout << "PR";
        a[i]--;
      } else
        cout << "R";
    }
    for (int i = n - 1; i > 0; i--) {
      if (a[i] > 0) {
        cout << "PL";
        a[i]--;
      } else
        cout << "L";
    }
  }
  cout << endl;
  return 0;
}
