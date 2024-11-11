#include <bits/stdc++.h>
using namespace std;
int n, a[99999];
long long x;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (x == 0 || x == 1 || x == 2) {
      a[i] = 0;
    } else {
      a[i] = x - 1 - x / 2;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << a[i];
  }
  return 0;
}
