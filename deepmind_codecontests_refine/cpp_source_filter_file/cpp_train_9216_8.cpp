#include <bits/stdc++.h>
using namespace std;
long long a, b, c, d;
long long n;
const int MAXN = 1e5 + 10;
int main() {
  cin >> n >> a >> b >> c >> d;
  long long ans = 0;
  for (long long i = 1; i <= n; ++i) {
    long long i2 = b + a + i - a - c;
    long long i3 = b + a + i - a - b;
    long long i4 = b + a + i - d - c;
    if (i2 <= n && i3 <= n && i4 <= n && i2 >= 1 && i3 >= 1 && i4 >= 1) ++ans;
  }
  cout << ans * n << endl;
  return 0;
}
