#include <bits/stdc++.h>
using namespace std;
using ll = long long;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &el : a) {
    cin >> el;
  }
  int mx = *max_element(a.begin(), a.end());
  int cnt = 0;
  for (auto el : a) {
    if (el == mx) {
      cnt++;
    }
  }
  if (cnt * 2 > n) {
    cout << "Bob\n";
  } else {
    cout << "Alice\n";
  }
}
