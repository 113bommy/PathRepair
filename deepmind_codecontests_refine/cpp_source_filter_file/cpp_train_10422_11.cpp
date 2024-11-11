#include <bits/stdc++.h>
using namespace std;
inline void init() {
  ios::sync_with_stdio(false);
  cin.tie(0);
}
void test() {
  int n;
  cin >> n;
  vector<int> l(n), r(n);
  for (int i = 0; i < n; i++) cin >> l[i] >> r[i];
  sort(l.begin(), l.end());
  sort(r.begin(), r.end());
  int ans = n;
  for (int i = 0; i < n; i++) ans += max(l[i], r[i]);
  cout << ans << '\n';
}
int main() {
  init();
  test();
  return 0;
}
