#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, n;
  cin >> n >> a;
  vector<int> x(n);
  for (int i = 0; i < n; i++) cin >> x[i];
  sort(x.begin(), x.end());
  if (n == 1)
    cout << 0;
  else if (a <= x[0]) {
    cout << x[n - 2] - a;
  } else if (a >= x[n - 1]) {
    cout << a - x[1];
  } else {
    int m = 20000001;
    if (m > (min(abs(a - x[0]), abs(a - x[n - 2])) + x[n - 2] - x[0]))
      m = min(abs(a - x[0]), abs(a - x[n - 2])) + x[n - 2] - x[0];
    if (m > (min(abs(a - x[1]), abs(a - x[n - 1])) + x[n - 1] - x[1]))
      m = min(abs(a - x[1]), abs(a - x[n - 1])) + x[n - 1] - x[1];
    cout << m;
  }
  return 0;
}
