#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  if (n % m == 0) {
    for (int i = 0; i < m; i++) {
      cout << n / m << " ";
    }
  } else {
    int a = (n / m) * m;
    int b = (n / m + 1) * m;
    int c = n - a;
    int d = b - n;
    for (int i = 0; i < d; i++) {
      cout << n / m << " ";
    }
    for (int i = 0; i < c; i++) {
      cout << n / m + 1 << " ";
    }
  }
  return 0;
}
