#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  string s;
  cin >> s;
  bool r = 0, l = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'R') r = 1;
    if (s[i] == 'L') l = 1;
  }
  if (r == 0) {
    for (int i = 0; i < n; i++)
      if (s[i] == 'L') {
        cout << i + 1 << " " << i;
        return 0;
      }
  }
  if (l == 0) {
    for (int i = n - 1; i > 0; i--)
      if (s[i] == 'R') {
        cout << i + 1 << " " << i + 2;
        return 0;
      }
  }
  for (int i = 0; i < n; i++)
    if (s[i] == 'R') {
      cout << i + 1 << " ";
      break;
    }
  for (int i = 0; i < n; i++)
    if (s[i] == 'L') {
      cout << i;
      break;
    }
  return 0;
}
