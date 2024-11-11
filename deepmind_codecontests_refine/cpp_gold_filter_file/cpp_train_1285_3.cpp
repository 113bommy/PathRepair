#include <bits/stdc++.h>
using namespace std;
int main() {
  long long k, b, n, t;
  cin >> k >> b >> n >> t;
  long long tm = k + b, an = n;
  while (tm <= t) {
    tm = tm * k + b;
    an--;
  }
  if (an <= 0)
    cout << 0 << endl;
  else
    cout << an << endl;
  return 0;
}
