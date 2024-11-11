#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int t, n, k;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    vector<int> a(n), b(n);
    int second = 0, p = 0;
    for (auto &x : a) cin >> x, second += x;
    for (auto &x : b) cin >> x;
    sort((a).begin(), (a).end());
    sort((b).rbegin(), (b).rend());
    for (int i = 0; i < n and k > 0; i++) {
      if (a[i] < b[p])
        second += b[p] - a[i], p++, k--;
      else
        break;
    }
    cout << second << "\n";
  }
}
