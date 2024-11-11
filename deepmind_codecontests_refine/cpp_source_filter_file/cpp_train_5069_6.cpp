#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, b;
  cin >> n >> b;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<int> v;
  int cnt = 0;
  for (int i = 0; i < n - 1; i++) {
    if (a[i] % 2 == 0)
      cnt++;
    else
      cnt--;
    if (cnt == 0) v.push_back(abs(a[i] - a[i + 1]));
  }
  sort(v.begin(), v.end());
  int ans = 0;
  for (auto i : v)
    if (b - i >= 0) ans++;
  cout << ans;
  return 0;
}
