#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(2 * n - 1);
  for (auto &i : a) cin >> i;
  int cnt = 0, ans = 0;
  for_each(a.begin(), a.end(), [&](int x) { cnt += x < 0; });
  for_each(a.begin(), a.end(), [&](int &x) {
    ans += abs(x);
    x = abs(x);
  });
  sort(a.begin(), a.end());
  if (cnt % 2 && n % 2 == 0) ans -= 2 * a[0];
  cout << ans << '\n';
  return 0;
}
