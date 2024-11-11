#include <bits/stdc++.h>
using namespace std;
int digit(int a) {
  int result = 0;
  while (a > 0) {
    result++;
    a /= 10;
  }
  return result;
}
int main() {
  int t;
  cin >> t;
  while (0 < t) {
    int n;
    cin >> n;
    int answer = 0;
    int c = digit(n);
    int c2 = n / pow(10, c - 1);
    int c3 = 0;
    if (9 < n) {
      c3 = c2;
      for (int i = 1; i < c; i++) {
        c3 = pow(10, i) * c2 + c3;
      }
    } else {
      c3 = n;
    }
    if (c3 <= n) {
      cout << (c - 1) * 9 + c2 << endl;
    } else {
      cout << (c - 1) * 9 + c2 - 1 << endl;
    }
    t--;
  }
}
