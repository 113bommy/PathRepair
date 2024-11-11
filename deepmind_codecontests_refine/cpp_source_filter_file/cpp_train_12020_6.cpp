#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, a, b, counter = 0;
  cin >> n >> m >> a >> b;
  if (m / b > a) {
    while (n) {
      n--;
      counter += a;
    }
    cout << counter << endl;
    return 0;
  } else {
    while (n >= m) {
      n -= m;
      counter += b;
    }
  }
  if (n == 0) {
    cout << counter << endl;
    return 0;
  } else {
    if (n * a < b) {
      while (n) {
        n--;
        counter += a;
      }
    } else
      counter += b;
  }
  cout << counter << endl;
  return 0;
}
