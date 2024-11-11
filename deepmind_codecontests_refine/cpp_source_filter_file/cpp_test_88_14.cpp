#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (long long &x : a) cin >> x;
  bool flag = 0;
  for (int i = 0; i < n - 1; i++) {
    if (a[i] > a[i + 1]) flag = true;
  }
  if (n % 2 == 0 || flag)
    cout << "YES\n";
  else
    cout << "NO\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) solve();
  return 0;
}
