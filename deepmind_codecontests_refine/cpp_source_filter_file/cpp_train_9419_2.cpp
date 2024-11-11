#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, last, temp, index;
  string s;
  cin >> s;
  n = s.size();
  last = s[n - 1] - '0';
  for (i = 0; i < n; i++) {
    temp = s[i] - '0';
    if (temp % 2 == 0 && temp > last) {
      break;
    }
  }
  if (i != n) {
    index = i;
    for (i = 0; i < n - 1; i++) {
      if (i == index) {
        cout << s[n - 1];
      } else {
        cout << s[i];
      }
    }
    cout << s[index];
    return 0;
  }
  for (i = n - 1; i >= 0; i--) {
    temp = s[i] - '0';
    if (temp % 2 == 0) {
      break;
    }
  }
  if (i < 0) {
    cout << -1;
    return 0;
  }
  index = i;
  for (i = 0; i < n - 1; i++) {
    if (i == index) {
      cout << s[n - 1];
    } else {
      cout << s[i];
    }
  }
  cout << s[index];
  return 0;
}
