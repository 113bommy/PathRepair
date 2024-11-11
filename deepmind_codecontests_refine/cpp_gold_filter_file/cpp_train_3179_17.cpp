#include <bits/stdc++.h>
using namespace std;
void solve();
int main() {
  solve();
  return 0;
}
void solve() {
  int i, n, d, j;
  cin >> n;
  vector<int> a(n), b(n);
  for (auto &it : a) cin >> it;
  sort(a.begin(), a.end());
  d = n / 2;
  j = 0;
  for (i = 0; i <= d; i++) {
    b[j] = a[i];
    j += 2;
  }
  reverse(a.begin(), a.end());
  j = 1;
  for (i = 0; i < n - d; i++) {
    b[j] = a[i];
    j += 2;
  }
  for (auto it : b) cout << it << " ";
}
