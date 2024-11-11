#include <bits/stdc++.h>
using namespace std;
int n;
int a[2000];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  int d = (n - a[0]) % n;
  for (int i = 1; i < n; i++) {
    if (i % 2 == 0) {
      if ((a[i] - d + n) % n != i) {
        cout << "No" << endl;
        exit(0);
      }
    } else {
      if ((a[i] + d + n) % n != i) {
        cout << "No" << endl;
        exit(0);
      }
    }
  }
  cout << "Yes" << endl;
}
