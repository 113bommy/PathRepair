#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int x = (m + 1) / 2;
  if (m % 2) {
    int i = 0;
    int flag = 1;
    while (n--) {
      if (!i) {
        cout << x << '\n';
      } else if (flag) {
        cout << x - i << '\n';
        flag = 0;
      } else {
        cout << x + i << '\n';
        flag = 1;
      }
      if (flag) {
        i += 1;
        if (x - i <= 0 || x + i > m) i = 0;
      }
    }
  } else {
    int i = 1;
    while (n) {
      cout << x + 1 - i << '\n';
      n -= 1;
      if (n) {
        cout << x + i << '\n';
        n -= 1;
      }
      i += 1;
      if (x - i < 0 || x + i > m) i = 1;
    }
  }
}
