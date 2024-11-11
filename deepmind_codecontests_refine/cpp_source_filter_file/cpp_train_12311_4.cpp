#include <bits/stdc++.h>
using namespace std;
int main() {
  int q;
  cin >> q;
  while (q--) {
    long long a, b, c;
    cin >> a >> b >> c;
    if (a * b <= c)
      cout << b + 1 << " " << -1 << "\n";
    else {
      if (c > a)
        cout << 1 << " " << b << "\n";
      else
        cout << -1 << " " << b << "\n";
    }
  }
}
