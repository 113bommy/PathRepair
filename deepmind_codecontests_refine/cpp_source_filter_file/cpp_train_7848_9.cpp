#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:258435456");
using namespace std;
int main() {
  long long n;
  long long a[1000001];
  cin >> n;
  long long p = 0, q;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    p += a[i];
  }
  sort(a, a + n);
  for (int i = 1; i <= n; i++)
    p += 2 * a[i - 1] * (i - 1) - 2 * a[i - 1] * (n - i);
  q = n;
  for (int i = 2; i < n; i++)
    while ((p % i == 0) && (q & i == 0)) {
      p /= i;
      q /= i;
    }
  cout << p << ' ' << q;
  return 0;
}
