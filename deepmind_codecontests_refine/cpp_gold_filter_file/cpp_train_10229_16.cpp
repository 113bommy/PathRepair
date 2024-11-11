#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, n, p = 0;
    cin >> a >> b >> n;
    while (a <= n && b <= n) {
      if (a > b)
        b = b + a;
      else
        a = a + b;
      p++;
    }
    cout << p << endl;
  }
  return 0;
}
