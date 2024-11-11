#include <bits/stdc++.h>
using namespace std;
int const lim = 2e5 + 3;
int main() {
  long long n;
  char x;
  scanf("%lld%c", &n, &x);
  long long ans = 0;
  if (n % 2 == 0) ans += 7, n--;
  if (n % 4 == 1)
    ans += 1ll * 2 * 6 * ((n - 1) / 4) + n;
  else
    ans += 1ll * 2 * 6 * ((n - 3) / 4) + n;
  if (x >= 'd')
    ans += abs(x - 'f');
  else
    ans += abs(x - 'a') + 3;
  cout << ans << endl;
}
