#include <bits/stdc++.h>
using namespace std;
int attainable[11111111];
int main() {
  long long a, b, mod;
  cin >> a >> b >> mod;
  long long x = 1000000000 % mod;
  memset(attainable, -1, sizeof attainable);
  long long curr = 0LL;
  for (int i = 0; i < a; i++) {
    if (attainable[curr] < 0) {
      if (curr != 0 && curr + b < mod) {
        cout << "1 " << setfill('0') << setw(9) << i << endl;
        return 0;
      }
      attainable[curr] = 1;
      curr = (curr + x) % mod;
    } else {
      break;
    }
  }
  cout << 2 << endl;
  return 0;
}
