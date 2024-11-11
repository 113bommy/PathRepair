#include <bits/stdc++.h>
using namespace std;
int main() {
  long i, j, n, m, a, b;
  cin >> n >> m >> a >> b;
  if (a * m <= b) {
    cout << n * a;
  } else {
    i = n / m;
    n %= m;
    cout << i * b + n * a;
  }
  return 0;
}
