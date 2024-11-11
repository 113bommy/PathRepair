#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int a, i, j, n, s, k = 0, b;
  cin >> n;
  for (j = 1; j <= n; j++) {
    cin >> a;
    b = ((1 + a) * a / 2);
    for (i = 1; i <= a; i = i * 2) {
      k = k + i;
      s = b - (2 * k);
    }
    cout << s << endl;
    k = 0;
  }
  return 0;
}
