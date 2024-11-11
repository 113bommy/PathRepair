#include <bits/stdc++.h>
using namespace std;
long long a, b, c;
vector<long long> ans;
inline long long check(long long x) {
  long long res = 0;
  for (; x > 0ll; x /= 10ll) {
    res += x % 10ll;
  }
  return res;
}
int main() {
  cin >> a >> b >> c;
  for (long long i = 1; i <= 100; ++i) {
    long long cur = 1;
    for (long long j = 1; j <= a; ++j) cur *= i;
    if (cur >= 1000000000ll) break;
    cur *= b;
    cur += c;
    if (cur >= 1000000000ll) break;
    if (cur > 0 && cur < 1000000000ll && check(cur) == i) ans.push_back(cur);
  }
  sort(ans.begin(), ans.end());
  cout << ans.size() << endl;
  for (int i = 0; i != ans.size(); ++i) printf("%I64d ", ans[i]);
  return 0;
}
