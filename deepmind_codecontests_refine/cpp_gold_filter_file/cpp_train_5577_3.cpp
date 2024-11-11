#include <bits/stdc++.h>
using namespace std;
long long n, a, b, c;
long long k;
int main() {
  cin >> n >> a >> b >> c;
  (n / 4 == 0) ? k = (4 - n) : k = ((n / 4) + 1) * 4 - n;
  if (k % 4 == 0) {
    cout << "0";
    exit(0);
  }
  if (k == 1) {
    cout << min(min(a, 3 * c), c + b);
    exit(0);
  }
  if (k == 2) {
    cout << min(min(a * 2, b), c * 2);
    exit(0);
  }
  if (k == 3) {
    cout << min(min(a * 3, a + b), c);
    exit(0);
  }
}
