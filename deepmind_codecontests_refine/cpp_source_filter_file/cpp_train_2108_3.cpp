#include <bits/stdc++.h>
using namespace std;
const long long MX = 303030;
const long long INF = 9e18;
long long b[34];
vector<long long> ans;
long long sol(long long cur, long long n) {
  ans.clear();
  for (int i = 0; i <= cur; i++) {
    if (i >= 1) ans.push_back(i);
    n -= b[i];
  }
  if (n >= b[cur]) {
    if (n <= 2 * b[cur]) {
      ans.push_back(n - b[cur]);
    } else {
      if (n <= 3 * b[cur]) {
        ans.push_back(0);
        ans.push_back(n - 2 * b[cur]);
      } else {
        long long x = n - 3 * b[cur];
        ans.push_back(x);
        ans.push_back(n - 2 * b[cur] - 2 * x);
      }
    }
    return 1;
  }
  return 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  b[0] = 1;
  for (int i = 1; i <= 32; i++) {
    b[i] = b[i - 1] * 2;
  }
  while (t--) {
    long long n;
    cin >> n;
    for (int i = 32; i >= 0; i--) {
      if (sol(i, n)) {
        cout << ans.size() << "\n";
        for (long long x : ans) {
          cout << x << " ";
        }
        cout << "\n";
        break;
      }
    }
  }
}
