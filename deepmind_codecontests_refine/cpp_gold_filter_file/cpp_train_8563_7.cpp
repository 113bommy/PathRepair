#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int s = 0, m;
  for (int i = (int)(2); i < (int)(n); i++) {
    m = n;
    while (m) {
      s += m % i;
      m /= i;
    }
  }
  int p = n - 2;
  for (int i = (int)(2); i < (int)(p + 1); i++)
    while (p % i == 0 && s % i == 0) {
      p /= i;
      s /= i;
    }
  cout << s << '/' << p;
  return 0;
}
