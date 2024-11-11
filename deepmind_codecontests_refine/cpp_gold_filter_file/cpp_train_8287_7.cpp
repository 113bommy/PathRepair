#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, c;
  cin >> n;
  cin >> a;
  cin >> b;
  cin >> c;
  int i = 1;
  int total = 0;
  char last = 'c';
  for (i = 2; i <= n; i++) {
    if (last == 'a') {
      if (b <= c) {
        total += b;
        last = 'c';
      } else {
        total += c;
        last = 'b';
      }
    } else if (last == 'b') {
      if (a <= c) {
        total += a;
        last = 'c';
      } else {
        total += c;
        last = 'a';
      }
    } else if (last == 'c') {
      if (a <= b) {
        total += a;
        last = 'b';
      } else {
        total += b;
        last = 'a';
      }
    }
  }
  cout << total;
  return 0;
}
