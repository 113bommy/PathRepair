#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n == 1)
    cout << 1;
  else {
    long long res = 13, s = 12;
    for (int i = 3; i <= n; ++i) {
      s += 12;
      res += s;
    }
    cout << res;
  }
  return 0;
}
