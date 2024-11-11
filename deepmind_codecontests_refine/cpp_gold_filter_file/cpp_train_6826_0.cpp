#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, p, m, a, b, c, d, e, sum = 0, l = -1000000;
  string name, max;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> name;
    cin >> p >> m >> a >> b >> c >> d >> e;
    sum = (p * 100) - (m * 50) + a + b + c + d + e;
    if (sum > l) {
      max = name;
      l = sum;
    }
  }
  cout << max;
  return 0;
}
