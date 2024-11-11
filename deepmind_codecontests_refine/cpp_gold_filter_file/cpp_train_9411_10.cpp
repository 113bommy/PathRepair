#include <bits/stdc++.h>
using namespace std;
mt19937 rng(time(0));
uniform_int_distribution<int> uid(-1e9, 1e9);
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long a, b, c;
  cin >> a >> b >> c;
  for (long long i = 0; i <= 2 * a; ++i)
    if (a - i >= 0 && b - i >= 0 && a + b - 2 * i == c)
      cout << i << " " << b - i << " " << a - i, exit(0);
  cout << "Impossible";
}
