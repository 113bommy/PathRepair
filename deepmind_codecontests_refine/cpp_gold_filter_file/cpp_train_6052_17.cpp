#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  t = 1;
  while (t--) {
    long long n, i, j, w, h, count = 0, sum = 0, total, k, T, breaks = 0, x = 1,
                             y = 1;
    string s;
    cin >> s;
    for (i = 0; i < s.size(); i++) {
      if (s[i] == '0') {
        cout << 1 << " " << x << endl;
        x = x % 4;
        x++;
      } else {
        cout << 4 << " " << y << endl;
        y = y + 2;
        y = y % 4;
      }
    }
  }
}
