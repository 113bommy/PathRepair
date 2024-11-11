#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  int n, a[100010], m = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] < 0) {
      m++;
    }
  }
  for (int i = 0; i < n; i++) {
    if (a[i] >= 0) {
      a[i] = -a[i] - 1;
      m++;
    }
  }
  if (m % 2 == 1) {
    int ind = -1;
    for (int i = 0; i < n; i++) {
      if (a[i] < 0) {
        if (ind == -1) {
          ind = i;
        } else if (a[i] < a[ind]) {
          ind = i;
        }
      }
    }
    a[ind] = -a[ind] - 1;
  }
  for (int i = 0; i < n; i++) {
    cout << a[i] << ' ';
  }
}
