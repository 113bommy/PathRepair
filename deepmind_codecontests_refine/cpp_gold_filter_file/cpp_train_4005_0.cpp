#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int q;
  long long a, b;
  cin >> q;
  while (q--) {
    cin >> a >> b;
    for (long long i = 1; i < 1e18; i <<= 1)
      if ((~a & i) && a + i <= b) a += i;
    cout << a << '\n';
  }
  return 0;
}
