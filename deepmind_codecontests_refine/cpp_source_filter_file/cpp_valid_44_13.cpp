#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int tt;
  cin >> tt;
  while (tt--) {
    long long int a, b;
    cin >> a >> b;
    if (a == 0 and b == 0)
      cout << 0 << endl;
    else if (a == b)
      cout << 1 << endl;
    else if (abs(b - a))
      cout << -1 << endl;
    else
      cout << 2 << endl;
  }
}
