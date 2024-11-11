#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
int ans, maxy, miny;
pair<int, int> a[3];
vector<int> y;
void get_input() {
  for (int i = 0; i < 3; i++) {
    cin >> a[i].first >> a[i].second;
  }
}
void solve() {
  sort(a, a + 3);
  maxy = max({a[0].second, a[1].second, a[2].second});
  miny = min({a[0].second, a[1].second, a[2].second});
  ans = max({a[0].first, a[1].first, a[2].first}) -
        min({a[0].first, a[1].first, a[2].first}) + maxy - miny;
}
void output() {
  ++ans;
  cout << ans << '\n';
  for (int i = a[0].first; i <= a[1].first - 1; i++) {
    cout << i << ' ' << a[1].second << '\n';
  }
  for (int i = 0; i < 3; i++) {
    y.push_back(a[i].second);
  }
  sort(y.begin(), y.end());
  for (int i = y[0]; i <= y[2]; i++) {
    cout << a[1].first << ' ' << i << '\n';
  }
  for (int i = a[2].first; i >= a[1].first + 1; i--) {
    cout << i << ' ' << a[1].second << '\n';
  }
}
int main() {
  ios_base ::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int tc = 1;
  while (tc--) {
    get_input(), solve(), output();
  }
  return 0;
}
