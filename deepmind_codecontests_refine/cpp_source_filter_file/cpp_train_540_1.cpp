#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
long long power(long long a, long long n) {
  long long res = 1;
  while (n != 0) {
    if (n % 2) {
      res = res * a;
      n--;
    } else {
      a = a * a;
      n = n / 2;
    }
  }
  return res;
}
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> v(n + 1);
  for (int i = 1; i <= n; i++) cin >> v[i];
  if (k > m) k = m - 1;
  int maxans = INT_MIN;
  for (int x = 0; x <= k; x++) {
    int minans = INT_MAX;
    for (int y = 0; y <= m - 1 - k; y++)
      minans = min(minans, max(v[x + y + 1], v[n - (k - x + m - 1 - k - y)]));
    maxans = max(maxans, minans);
  }
  cout << maxans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
}
