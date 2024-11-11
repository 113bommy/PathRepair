#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const long long N = 1000000007;
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long w1, h1, w2, h2;
  cin >> w1 >> h1 >> w2 >> h2;
  long long ans = 2 * (h1 + h2 + 2) + w1 + w2;
  if (w2 < w1)
    cout << ans + w1 - w2 << endl;
  else
    cout << ans << endl;
  return 0;
}
