#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, i, j, m;
  long long t;
  cin >> t;
  while (t--) {
    long long a, b, c, n, bo;
    cin >> a >> b >> n;
    c = a ^ b;
    bo = n / 3;
    if (bo == 0)
      cout << a << endl;
    else if (bo == 1)
      cout << b << endl;
    else
      cout << c << endl;
  }
}
