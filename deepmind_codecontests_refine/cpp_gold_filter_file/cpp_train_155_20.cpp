#include <bits/stdc++.h>
using namespace std;
template <class T>
bool sin(T &a, T b) {
  return a > b ? (a = b, true) : false;
}
template <class T>
bool sax(T &a, T b) {
  return a < b ? (a = b, true) : false;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.precision(10);
  cout << fixed;
  ;
  int n, k, a, b, c, d;
  cin >> n >> k >> a >> b >> c >> d;
  if (k <= n or n <= 4) return cout << -1, 0;
  vector<int> ans(n);
  for (int i = 0; i < n; i++) ans[i] = i + 1;
  auto it = find(ans.begin(), ans.end(), a);
  int ind = it - ans.begin();
  swap(ans[0], ans[ind]);
  it = find(ans.begin(), ans.end(), b);
  ind = it - ans.begin();
  swap(ans[n - 2], ans[ind]);
  it = find(ans.begin(), ans.end(), c);
  ind = it - ans.begin();
  swap(ans[1], ans[ind]);
  it = find(ans.begin(), ans.end(), d);
  ind = it - ans.begin();
  swap(ans[n - 1], ans[ind]);
  for (int i = 0; i < n; i++) {
    if (i == n - 2) {
      cout << ans[n - 1] << " " << ans[n - 2] << "\n";
      break;
    }
    cout << ans[i] << " ";
  }
  swap(ans[0], ans[1]);
  for (int i = 0; i < n; i++) cout << ans[i] << " ";
  cout << "\n";
  return 0;
}
