#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) cin >> i;
  int ans = 1;
  bool u = false, d = false;
  for (int i = 1; i < n - 1; ++i) {
    if (a[i - 1] < a[i]) u = true;
    if (a[i - 1] > a[i]) d = true;
    if (u && d) {
      u = d = false;
      ans++;
    }
  }
  cout << ans << endl;
}
