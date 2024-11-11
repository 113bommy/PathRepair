#include <bits/stdc++.h>
using namespace std;
const long long A = 100000000000000LL, N = 228228;
long long a, i, j, n, o, d, m;
int main() {
  cin >> n >> m;
  cin >> a;
  for (i = 1; i < n; i++) {
    cin >> a;
    if (o - (i - d) * ((n - i - 1) * a) < m)
      d++, cout << i + 1 << "\n";
    else
      o += a * (i - d);
  }
}
