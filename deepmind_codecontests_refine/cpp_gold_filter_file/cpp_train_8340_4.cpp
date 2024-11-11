#include <bits/stdc++.h>
using namespace std;
const int ms = 2e5 + 200;
long long a[ms], b[ms];
int main() {
  int n;
  cin >> n;
  for (int i = 0; (i << 1) < n; i++) {
    scanf("%lld", b + i);
  }
  a[0] = 0;
  a[n - 1] = b[0];
  for (int i = 1; i < n / 2; i++) {
    long long lo = max(a[i - 1], b[i] - a[n - i]);
    a[i] = lo;
    a[n - i - 1] = b[i] - lo;
  }
  for (int i = 0; i < n; i++) {
    printf("%lld%c", a[i], " \n"[i + 1 == n]);
  }
}
