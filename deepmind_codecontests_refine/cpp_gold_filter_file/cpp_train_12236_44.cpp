#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b;
  cin >> n >> a >> b;
  if (b == 0)
    cout << a;
  else {
    if (b < 0)
      while (b < 0) b += n;
    b %= n;
    cout << (a + b == n ? a + b : (a + b) % n) << endl;
  }
  return 0;
}
