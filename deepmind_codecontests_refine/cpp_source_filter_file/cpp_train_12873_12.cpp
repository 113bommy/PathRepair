#include <bits/stdc++.h>
using namespace std;
int main() {
  double k, n, s, p, m = 10 * 10 * 10 * 10;
  float a;
  cin >> k >> n >> s >> p;
  for (int i = 1; i <= m; i++) {
    if (s * i >= n) {
      m = i;
      break;
    }
  }
  a = ceil((m * k) / p);
  cout << a;
}
