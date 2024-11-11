#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n;
  cin >> n;
  string s;
  cin >> s;
  int a[10] = {};
  for (int i = 0; i < n; i++) {
    if (s[i] == 'L') {
      for (int j = 0; j <= 9; j++) {
        if (a[j] == 0) {
          a[j] = 1;
          break;
        }
      }
    } else if (s[i] == 'R') {
      for (int j = 9; j >= 0; j--) {
        if (a[j] == 0) {
          a[j] = 1;
          break;
        }
      }
    } else {
      int x = s[i] - '0';
      a[x] = 0;
    }
  }
  for (int i = 0; i <= 9; i++) cout << a[i];
  return 0;
}
