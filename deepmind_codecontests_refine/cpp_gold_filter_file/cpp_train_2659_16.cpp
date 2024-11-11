#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, h, s = 0, t;
  while (cin >> n >> h) {
    while (n--) {
      cin >> t;
      if (t > h)
        s = s + 2;
      else
        s++;
    }
    cout << s;
  }
  return 0;
}
