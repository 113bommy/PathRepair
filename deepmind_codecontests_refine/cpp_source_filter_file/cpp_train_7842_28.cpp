#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  long long k, b, n, t;
  cin >> k >> b >> n >> t;
  int ans = -1;
  long long cur = 1;
  while (cur < t) {
    cur = cur * k + b;
    ++ans;
  }
  cout << max(0LL, n - ans) << endl;
  return 0;
}
