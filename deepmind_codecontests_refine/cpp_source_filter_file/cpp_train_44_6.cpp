#include <bits/stdc++.h>
using namespace std;
int main() {
  int sum, a, b, c, ans = 0;
  cin >> sum >> a >> b >> c;
  for (int i = 0; i <= a; i += 2)
    for (int j = 0; j <= c; ++j)
      if (sum - i / 2 - 2 * j <= a && sum - i / 2 - 2 * j >= 0) ans++;
  cout << ans << endl;
  return 0;
}
