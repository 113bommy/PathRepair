#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    long long x;
    cin >> x;
    long long cnt = 0;
    bool f = 1;
    while (1) {
      if (x == 1)
        break;
      else if (x % 2 == 0)
        x = x / 2;
      else if (x % 3 == 0)
        x = (2 * x) / 3;
      else if (x % 5 == 0)
        x = (4 * x) / 5;
      else
        f = 0;
      if (!f) {
        break;
      }
      cnt++;
    }
    if (x == 1)
      cout << cnt << endl;
    else
      cout << "-1" << endl;
  }
  return 0;
}
