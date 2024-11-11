#include <bits/stdc++.h>
using namespace std;
int n, m, a, b, c, d;
int main() {
  cin >> n >> m >> a >> b >> c >> d;
  if (m < n + 1 || n == 4) {
    cout << -1;
    return 0;
  }
  cout << a << " " << c << " ";
  for (int i = 1; i < n + 1; i++) {
    if (i != a and i != b and i != c and i != d) {
      cout << i << " ";
    }
  }
  cout << d << " " << b << "\n";
  cout << c << " " << a << " ";
  for (int i = 1; i < n + 1; i++) {
    if (i != a and i != b and i != c and i != d) {
      cout << i << " ";
    }
  }
  cout << b << " " << d;
}
