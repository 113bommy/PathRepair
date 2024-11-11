#include <bits/stdc++.h>
using namespace std;
int c;
int main() {
  cin >> c;
  for (int i = sqrt(c); i <= c; i++) {
    if (c % i == 0) {
      cout << min(i, c / i) << " " << max(i, c / i);
      break;
    }
  }
  return 0;
}
