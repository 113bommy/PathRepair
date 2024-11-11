#include <bits/stdc++.h>
using namespace std;
long long a, b, c, d, i, n;
long long x[10002];
int main() {
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> x[i];
  }
  for (i = 0; i < n; i++) {
    a = x[i + 1] - x[i];
    b = x[i] - x[i - 1];
    c = x[i] - x[0];
    d = x[n - 1] - x[i];
    if (i == 0) {
      cout << a << " " << d;
      cout << endl;
      continue;
    }
    if (i == n - 1) {
      cout << b << " " << c;
      cout << endl;
      continue;
    }
    cout << min(a, b) << " " << max(c, d);
    cout << endl;
  }
  return 0;
}
