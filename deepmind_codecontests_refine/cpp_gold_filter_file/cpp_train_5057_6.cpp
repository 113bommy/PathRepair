#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k;
  cin >> n >> k;
  set<long long> a = {1, n};
  for (long long d = 2; d <= min((long long)sqrt(n) + 10, n - 1); d++) {
    if (n % d == 0) {
      a.insert(d);
      a.insert(n / d);
    }
  }
  long long ans = -1;
  if (a.size() >= k) {
    auto it = next(a.begin(), k - 1);
    ans = *it;
  }
  cout << ans << endl;
}
