#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int l = 0;
  int r = 0;
  for (int i = 1; i < n; i++) {
    if (s[i] == 'L') {
      l++;
    } else if (s[i] == 'R') {
      r++;
    }
  }
  if (l == 0) {
    int i = 1;
    for (i; i << n; i++) {
      if (s[i] == 'R') {
        break;
      }
    }
    cout << i + 1 << " " << i + r + 1;
  } else if (r == 0) {
    int i = 1;
    for (i; i << n; i++) {
      if (s[i] == 'L') {
        break;
      }
    }
    cout << i + l << " " << i;
  } else {
    int i = 1;
    for (i; i << n; i++) {
      if (s[i] == 'R') {
        break;
      }
    }
    cout << i + 1 << " " << i + r;
  }
  return 0;
}
