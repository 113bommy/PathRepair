#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i;
  string s;
  cin >> n >> s;
  int a[n];
  fill(a, a + n, 1);
  for (i = 0; i < n - 1; i++) {
    if (s[i] == 'R') {
      a[i + 1] = a[i] + 1;
    }
    if (s[i] == '=') {
      a[i + 1] = a[i];
    }
  }
  for (i = n - 2; i >= 0; i--) {
    if (s[i] == 'L' && a[i] <= a[i + 1]) {
      a[i] = a[i + 1] + 1;
    }
    if (s[i] == '=' && a[i] < a[i + 1]) {
      a[i] = a[i + 1];
    }
  }
  for (i = 0; i < n - 1; i++) {
    if (s[i] == 'L' && a[i] <= a[i + 1]) {
      a[i] = a[i + 1] + 1;
    }
    if (s[i] == '=' && a[i] != a[i + 1]) {
      a[i] = max(a[i], a[i + 1]);
      a[i + 1] = max(a[i], a[i + 1]);
    }
    if (s[i] == 'R' && a[i] >= a[i + 1]) {
      a[i + 1] = a[i] + 1;
    }
  }
  for (i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  return 0;
}
