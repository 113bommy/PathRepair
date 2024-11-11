#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 100, maxl = ((((3) * (3))) * (((3) * (3)))), lg = 21;
inline long long fc(int n) {
  long long ans = 1;
  while (n--) ans *= 10LL;
  return ans - 1LL;
}
inline int LOG(long long a) {
  stringstream ss;
  ss << a;
  string s;
  ss >> s;
  return (int)s.size();
}
int main() {
  long long l, r, ans = 0LL;
  cin >> l >> r;
  for (int(i) = (1); (i) < (18); ++(i)) {
    long long first = fc(i), second = first / 2LL;
    if (l <= second && second <= r) ans = max(ans, second * (first - second));
    if (LOG(l) == i) ans = max(ans, l * (first - l));
    if (LOG(r) == i) ans = max(ans, r * (first - r));
  }
  cout << ans << endl;
}
