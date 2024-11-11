#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, c = 0, se = 0, l = 0;
  char s[200005];
  cin >> n >> a >> b;
  cin >> s;
  for (int i = 0; i < n && a + b > 0; i++) {
    if (s[i] == '*') {
      c = 0;
    } else {
      if (a > b) {
        if (c != 1) {
          se++;
          a--;
          c = 1;
        } else if (b > 0) {
          se++;
          b--;
          c = 2;
        } else {
          c = 0;
        }
      } else {
        if (c != 2) {
          se++;
          b--;
          c = 2;
        } else if (a > 0) {
          se++;
          a--;
          c = 1;
        } else {
          c = 0;
        }
      }
    }
  }
  cout << se << endl;
  return 0;
}
