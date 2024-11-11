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
  char last = 'a';
  for (i = 2; i <= n; i++) {
    if (last == 'a') {
      if (b <= c) {
        total += b;
        last = 'b';
      } else {
        total += c;
        last = 'c';
      }
    } else if (last == 'b') {
      if (a <= c) {
        total += a;
        last = 'a';
      } else {
        total += c;
        last = 'c';
      }
    } else if (last == 'c') {
      if (a <= b) {
        total += a;
        last = 'a';
      } else {
        total += b;
        last = 'b';
      }
    }
  }
  cout << total;
  return 0;
}
