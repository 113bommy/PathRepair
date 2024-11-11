#include <bits/stdc++.h>
using namespace std;
bool palindrome(string a) {
  for (int i = 0; i < (a.length() - a.length() % 2) / 2 + 1; i++) {
    if (a[i] == a[a.length() - i - 1])
      continue;
    else
      return 0;
  }
  return 1;
}
int main() {
  string a, b;
  int t, i;
  cin >> t;
  for (i = 1; i <= t; i++) {
    cin >> a;
    if (palindrome(a)) {
      b = a;
      for (int j = 0; j < a.length() - 1; j++) {
        for (int q = j + 1; q < a.length(); q++) {
          if (a[j] != a[q]) {
            char c = a[j];
            a[j] = a[q];
            a[q] = c;
            break;
          }
        }
      }
      if (a.compare(b) == 0)
        cout << -1 << endl;
      else
        cout << a;
    } else
      cout << a << endl;
  }
}
