#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  long long seq[51];
  seq[0] = 0;
  seq[1] = 1;
  for (long long i = 2; i < 51; i++) seq[i] = seq[i - 1] + (1 << (i - 2));
  while (t--) {
    long long a, b, m;
    cin >> a >> b >> m;
    if (a == b) {
      cout << "1 " << a << "\n";
      continue;
    }
    long long k;
    for (k = 2; k <= 50; k++) {
      if (b < ((a + 1) << (k - 2))) {
        k = 51;
        break;
      }
      if (b >= ((a + 1) << (k - 2)) && b <= ((a + m) << (k - 2))) break;
    }
    if (k == 51)
      cout << "-1\n";
    else {
      cout << k << " " << a << " ";
      for (long long i = k; i >= 3; i--) {
        long long temp = min((b >> (i - 3)) - 2 * a - 1, m);
        cout << a + temp << " ";
        a = 2 * a + temp;
      }
      cout << b << "\n";
    }
  }
  return 0;
}
