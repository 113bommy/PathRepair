#include <bits/stdc++.h>
using namespace std;
long long n;
int main() {
  cin >> n;
  long long ans = 0;
  for (long long i = 1; i * i <= n; i++) {
    long long x = i, tmp = n - (x << 1);
    if (tmp % 3 != 0) continue;
    long long y = tmp / 3;
    if (y >= (x * (x + 1) / 2)) ans += 1;
  }
  cout << ans << endl;
}
