#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, b, d, c, i, j;
  cin >> n >> m;
  if (m == 0) {
    cout << "0";
  } else {
    if (n % 2 == 0) {
      if (m <= floor(n / 2)) {
        cout << m;
      } else {
        c = floor(n / 2);
        b = m - (c);
        c = c - b;
        cout << c;
      }
    } else {
      if (m <= floor(n / 2)) {
        cout << m;
      } else if (m == floor(n / 2) + 1) {
        cout << floor(n / 2);
      } else {
        c = floor(n / 2);
        b = m - (c);
        c = c - b;
        cout << c + 1;
      }
    }
  }
}
