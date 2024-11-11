#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b;
  cin >> a >> b;
  if (a == b) {
    cout << "infinity";
    return 0;
  }
  if (a <= 2 * b) {
    cout << 0;
    return 0;
  }
  int q = sqrt(a - b);
  int l = 0;
  for (int i = 1; i <= q; i++) {
    if ((a - b) % i == 0) {
      if (i > b) {
        l = l + 1;
      }
      if ((a - b) / i > b) {
        l = l + 1;
      }
    }
  }
  double e = sqrt(a - b);
  if ((e - q == 0) && (q > b)) l = l - 1;
  cout << l;
  return 0;
}
