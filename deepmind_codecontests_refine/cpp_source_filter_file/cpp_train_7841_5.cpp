#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int s = 0;
  s = n;
  int t = 0;
  t = (int)sqrt(n);
  t += 10;
  while (n > 1) {
    bool b = 0;
    for (int i = 2; i < t; i++) {
      if (n % i == 0) {
        n /= i;
        s += n;
        b = 1;
        break;
      }
    }
    if (b) {
      n /= n;
      s += n;
      b = 0;
    }
  }
  cout << s;
  return 0;
}
