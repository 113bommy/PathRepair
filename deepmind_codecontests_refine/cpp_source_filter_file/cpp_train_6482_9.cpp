#include <bits/stdc++.h>
static const auto fast = []() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  return 0;
}();
using namespace std;
int32_t main() {
  long long T;
  cin >> T;
  while (T--) {
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
    }
    bool ans = true;
    for (long long i = 0; i < n; i++) {
      if (a[i] == 1) {
        ans = !ans;
        if (i + 1 == n) ans = !ans;
      } else
        break;
    }
    if (ans)
      cout << "FIRST\n";
    else
      cout << "SECOND\n";
  }
  return 0;
}
