#include <bits/stdc++.h>
using namespace std;
long long n, ns, a[1111];
void ok(long long x) {
  long long l = 0, r = min(2000000000ll, (1ll << 18) / (x + 1) + 1);
  while (l < r) {
    long long m = (l + r) / 2;
    if (m * (m - 1) / 2 + m * x >= n)
      r = m;
    else
      l = m + 1;
    if (m * (m - 1) / 2 + m * x == n && m % 2) a[++ns] = m + m * x;
  }
}
int main() {
  while (cin >> n) {
    ns = 0;
    for (int i = 0; i < 62; i++) ok((1ll << i) - 1);
    if (!ns)
      cout << -1 << endl;
    else {
      for (int i = 1; i <= ns; i++) cout << a[i] << endl;
    }
  }
  return 0;
}
