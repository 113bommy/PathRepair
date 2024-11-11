#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, p;
  cin >> n >> p;
  vector<char> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[i] = a[i];
  }
  bool result = false;
  for (int i = 0; i < n - p; i++) {
    if (a[i] == '.' || a[i + p] == '.') {
      result = true;
      if (a[i] == a[i + p]) {
        b[i] = '1';
        b[i + p] = '0';
        continue;
      }
      if (a[i] == '0') {
        b[i + p] = '1';
        continue;
      }
      if (a[i] == '1') {
        b[i + p] = '0';
        continue;
      }
      if (a[i + p] == '0') {
        b[i] = '1';
        continue;
      }
      if (a[i + p] == '1') {
        b[i] = '0';
        continue;
      }
    } else {
      if (a[i] != a[i + p]) {
        result = true;
      }
    }
  }
  if (result) {
    for (int i = 0; i < n; i++) {
      cout << ((b[i] != '.') ? b[i] : '1') << " ";
    }
  } else {
    cout << "No" << endl;
    return 0;
    ;
  }
  return 0;
}
