#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, i, x, s = 0;
  cin >> n;
  x = n / 10;
  if (n > 9) {
    s += n;
    for (i = 9;; i = i * 10 + 9) {
      s += n - i;
      x /= 10;
      if (x == 0) break;
    }
  } else
    s = n;
  cout << s << endl;
  return 0;
}
