#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int a, e, b = 1, c = 1, d = 0, f = 0;
  cin >> a;
  for (int i = 0; i < a; i++) {
    cin >> e;
    if (e == 1 && b == 1) {
      if (c == 1) {
        d = 1;
        c = 0;
        continue;
      }
      if (d == 1) {
        d = 0;
        c = 1;
        continue;
      }
    }
    if (e == 1 && b == 0) f = 1;
    if (e == 2 && c == 1) {
      if (b == 1) {
        b = 0;
        d = 1;
        continue;
      }
      if (d == 0) {
        d = 0;
        b = 1;
        continue;
      }
    }
    if (e == 2 && c == 0) f = 1;
    if (e == 3 && d == 1) {
      if (b == 1) {
        b = 0;
        c = 1;
        continue;
      }
      if (c == 0) {
        c = 0;
        b = 1;
        continue;
      }
    }
    if (e == 3 && d == 0) f = 1;
  }
  if (f == 1) {
    cout << "NO";
    return 0;
  }
  cout << "YES";
}
