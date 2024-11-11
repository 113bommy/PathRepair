#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
const long long mod = 1e9 + 7;
const int X = 500000;
void flash() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(12);
}
bool org(const pair<int, int> &a, const pair<int, int> &b) {
  if (a.first > b.first || (a.first == b.first && a.second < b.second))
    return true;
  return false;
}
void solve();
int32_t main() {
  flash();
  int t;
  t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
void solve() {
  int n, k;
  cin >> n >> k;
  int a[n];
  int neg = 0;
  int minp = 1e9;
  int minn = 1e9;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] < 0) {
      neg++;
      minn = min(minn, abs(a[i]));
    } else {
      minp = min(minp, a[i]);
    }
  }
  sort(a, a + n);
  long long sum = 0;
  if (neg >= k) {
    for (int i = 0; i < k; i++) sum += abs(a[i]);
    for (int i = k; i < n; i++) sum += a[i];
  } else {
    for (int i = 0; i < n; i++) {
      sum += abs(a[i]);
    }
    int rem = k - neg;
    if (rem % 2 == 1) sum -= 2 * min(minp, minn);
  }
  cout << sum;
  return;
}
