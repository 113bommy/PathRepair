#include <bits/stdc++.h>
using namespace std;
const double pi = 3.14;
int main() {
  int n, m, a, b;
  cin >> n >> m >> a >> b;
  if (m * a <= b) {
    cout << n * a;
    return 0;
  } else {
    cout << n / m * b + min(a, b);
  }
}
