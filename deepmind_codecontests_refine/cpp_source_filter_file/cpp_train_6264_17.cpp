#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int pos = -1;
  int mx = INT_MIN;
  for (int i = 0; i < n; i++) {
    if (a[i] < mx) {
      mx = a[i];
      pos = i;
    }
  }
  int flag = 1;
  for (int i = pos - 1; i >= 1; i--) {
    if (a[i] < a[i - 1]) {
      flag = 0;
      break;
    }
  }
  if (!flag) {
    cout << "NO" << endl;
  } else {
    for (int i = pos + 1; i < n - 1; i++) {
      if (a[i] < a[i + 1]) {
        flag = 0;
        break;
      }
    }
    if (!flag) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  }
  return 0;
}
