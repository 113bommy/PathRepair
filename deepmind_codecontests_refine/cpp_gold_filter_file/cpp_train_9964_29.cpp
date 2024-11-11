#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
const int mod = 1e9 + 7;
const double eps = 1e-9;
const double pi = acos(-1.0);
const int inf = 0x3f3f3f3f;
long long n;
long long a[15] = {0, 4, 10, 20, 35, 56, 83, 116, 155, 198, 244, 292, 341};
int main() {
  cin >> n;
  if (n <= 12)
    printf("%lld\n", a[n]);
  else
    printf("%lld\n", 341 + (n - 12) * 49);
  return 0;
}
