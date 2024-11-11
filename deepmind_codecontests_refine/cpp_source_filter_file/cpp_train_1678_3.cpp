#include <bits/stdc++.h>
using namespace std;
int main() {
  long long i, j, k = 0, l, n, m, a, b, c, d;
  scanf("%lld", &n);
  while (n--) {
    k = 0;
    cin >> a >> b >> c >> d;
    if (a < b) {
      cout << 0 << endl;
      continue;
    }
    k += ((c - 1) / b);
    k += (a / b - c / b);
    printf("%lld\n", k);
  }
}
