#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[120][2], n, k, mini = -100, s = 0;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (a[i][0] > a[j][0]) {
        swap(a[i][0], a[j][0]);
        swap(a[i][1], a[j][1]);
      }
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    while (k > a[i][0]) {
      k--;
      s++;
    }
    if (s < a[i][1]) {
      s = a[i][1];
    }
    while (k > 0 && i == 0) {
      k--;
      s++;
    }
  }
  cout << s;
}
