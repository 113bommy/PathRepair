#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, d;
  cin >> n >> d;
  string s;
  cin >> s;
  int a = 1, c = 0, max = 0;
  while (a != n) {
    if (s[a + d - 1] == '1' && a + d - 1 < n)
      a = a + d;
    else {
      for (int i = a + d - 2; i >= a; i--) {
        if (s[i] == '1' && i < n) {
          a = i + 1;
          c = 1;
          break;
        }
      }
      if (c == 0) {
        c = -1;
        break;
      }
    }
    max++;
    c = 0;
  }
  if (c == -1)
    cout << "-1";
  else
    cout << max;
}
