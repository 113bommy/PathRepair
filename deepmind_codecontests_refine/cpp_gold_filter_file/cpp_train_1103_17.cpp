#include <bits/stdc++.h>
using namespace std;
int k, n, a[1000000], m;
int main() {
  ios::sync_with_stdio(false);
  cin >> k;
  string s;
  cin >> s;
  for (auto c : s) {
    m += c - '0';
  }
  if (m < k) {
    for (auto c : s) {
      a[n++] = '9' - c;
    }
  }
  sort(a, a + n, greater<int>());
  int diff = abs(m - k), ans = 0;
  for (int i = 0; i < n; i++) {
    ans++;
    diff -= a[i];
    if (diff <= 0) break;
  }
  cout << ans;
}
