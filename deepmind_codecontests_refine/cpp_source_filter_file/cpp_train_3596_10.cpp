#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, x;
  string d;
  int t, m = 0;
  cin >> n >> x;
  for (int i = 0; i < n; i++) {
    cin >> d >> t;
    if (d[0] == '+') x += t;
    if (d[0] == '-') {
      if (x > t)
        x -= t;
      else
        m++;
    }
  }
  cout << x << " " << m;
  return 0;
}
