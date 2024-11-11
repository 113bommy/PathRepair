#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);
    long long x = (2 * b - a);
    if (x % 3 == 0 && b >= 2 * a)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
