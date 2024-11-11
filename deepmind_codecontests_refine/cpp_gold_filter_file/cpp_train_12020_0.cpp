#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, a, b;
  cin >> n >> m >> a >> b;
  int oneride = n * a;
  int seconedride;
  if (m * a <= b) {
    cout << n * a;
  } else {
    if (n % m == 0) {
      seconedride = (n / m) * b;
    } else {
      if (m > n) {
        seconedride = b;
      } else {
        seconedride = (n / m) * b;
        if ((n % m) < m && b < a) {
          seconedride += b;
        } else if (a > b) {
          seconedride += (n % m) * b;
        } else {
          seconedride += (n % m) * a;
        }
      }
    }
    if (oneride <= seconedride) {
      cout << oneride;
    } else {
      cout << seconedride;
    }
  }
}
