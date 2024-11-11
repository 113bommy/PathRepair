#include <bits/stdc++.h>
using namespace std;
bool isPrime(long long n) {
  if (n == 1) return false;
  if (n == 2) return true;
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
void solve() {
  long long n, k;
  cin >> n >> k;
  vector<pair<long long, long long>> a(n);
  long long y = 0;
  long long i = 0;
  for (auto &x : a) {
    cin >> x.first;
    x.second = i;
    i++;
  }
  sort(a.begin(), a.end());
  for (long long i = 0; i < n - 1; i++) {
    if (a[i + 1].second - 1 != a[i].second) {
      y++;
    }
  }
  if (y + 1 == k) {
    cout << "Yes" << endl;
  } else
    cout << "No" << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
