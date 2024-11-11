#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, x, y;
  cin >> n >> x >> y;
  long long m = y - n + 1;
  long long s = m * m + n - 1;
  if (s < x || m < 1)
    cout << -1;
  else {
    cout << m << endl;
    for (int i = 1; i < n; i++) cout << 1 << endl;
  }
  return 0;
}
