#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, k = 0, m, h, d, c = 100000000007, ans = 0;
    vector<int> a(3);
    for (auto &x : a) cin >> x;
    sort(a.begin(), a.end());
    if (a[2] < (a[0] + a[1]) || (a[2] - 1) <= (a[0] + a[1])) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
