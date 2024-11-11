#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  short t;
  cin >> t;
  unsigned long long int a, b, n;
  while (t--) {
    cin >> a >> b >> n;
    if (a < b) {
      a = a + b;
      b = a - b;
      a = a - b;
    }
    int c = 0;
    while (a <= n && b <= n) {
      c++;
      if (c % 2 != 0)
        a += b;
      else
        b += a;
    }
    cout << c << "\n";
  }
  return 0;
}
