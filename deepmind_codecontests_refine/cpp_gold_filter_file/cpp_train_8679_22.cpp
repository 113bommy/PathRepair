#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  bool is_present[3001] = {false};
  long long end;
  for (long long i = 0; i < n; ++i) {
    long long x;
    cin >> x;
    is_present[x] = true;
    end = max(end, x);
  }
  for (long long i = 1; i <= end + 1; ++i) {
    if (!is_present[i]) {
      cout << i;
      return 0;
    }
  }
  return 0;
}
