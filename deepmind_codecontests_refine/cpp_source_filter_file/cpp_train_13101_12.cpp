#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, c, k;
  cin >> n >> c >> k;
  vector<int> t(n + 1);
  for (int i = 0; i < n; ++i) {
    cin >> t[i];
  }
  t[n] = 2002002002;
  sort(t.begin(), t.end());
  int l = 0, ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (i - l >= c || t[i] - t[l] >= k) {
      ans++;
      l = i;
    }
  }
  cout << ans << endl;
}
