#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long N = 3e5 + 5;
const long long INF = 1e12;
void solve() {
  long long n, m;
  cin >> n >> m;
  bool isZeroPresent = false;
  long long minVal = INT_MAX;
  long long ans = 0;
  long long numNeg = 0;
  for (long long i = 0; i < m * n; i++) {
    long long val;
    cin >> val;
    if (val == 0) {
      isZeroPresent = true;
    }
    ans += abs(val);
    minVal = min(minVal, abs(val));
    if (val < 0) {
      numNeg++;
    }
  }
  if (numNeg % 2 == 0 || isZeroPresent) {
  } else {
    ans -= (2 * minVal);
  }
  cout << ans << "\n";
  return;
}
int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  for (long long i = 0; i < t; i++) {
    solve();
  }
  return 0;
}
