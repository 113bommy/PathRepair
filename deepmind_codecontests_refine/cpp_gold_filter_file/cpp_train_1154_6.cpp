#include <bits/stdc++.h>
using namespace std;
int main() {
  long int n, m, d, c = 0, v;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    v = 0;
    cin >> d;
    if (d >= (m - c)) {
      d = d - (m - c);
      v = 1;
      v = v + (d / m);
      c = d % m;
    } else {
      c = c + d;
    }
    cout << v << ' ';
  }
  return 0;
}
