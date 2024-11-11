#include <bits/stdc++.h>
using namespace std;
int main() {
  int c, d, m, n, k, s = 0;
  cin >> c >> d >> n >> m >> k;
  if (k >= m * n)
    cout << "0";
  else {
    int x = n * m - k;
    if (d < n * c)
      s = ceil((float)x / d);
    else {
      s = x / n * c + min(c, x % n * d);
    }
    cout << s;
  }
}
