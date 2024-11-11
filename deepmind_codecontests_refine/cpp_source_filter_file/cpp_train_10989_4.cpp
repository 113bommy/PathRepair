#include <bits/stdc++.h>
using namespace std;
long long n, f[70];
int main() {
  f[1] = 2;
  f[0] = 1;
  for (int i = 2; i < 70; ++i) {
    f[i] = f[i - 1] + f[i - 2];
  }
  scanf("%lld", &n);
  cout << upper_bound(f, f + 70, n) - f - 1;
  return 0;
}
