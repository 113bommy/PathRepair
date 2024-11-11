#include <bits/stdc++.h>
using namespace std;
int main() {
  int k, n, a;
  int max = -1000000100;
  int min = 1000000100;
  cin >> n >> k;
  if (k == 1) {
    for (int i = 0; i < n; i++) {
      cin >> a;
      if (a < min) min = a;
    }
    cout << min;
  }
  if (k > 2) {
    for (int i = 0; i < n; i++) {
      cin >> a;
      if (a > max) max = a;
    }
    cout << max;
  }
  if (k == 2) {
    int b[n];
    for (int i = 0; i < n; i++) {
      cin >> b[i];
    }
    if (b[0] <= b[n - 1]) cout << b[n - 1];
    if (b[n - 1] < b[0]) cout << b[0];
  }
}
