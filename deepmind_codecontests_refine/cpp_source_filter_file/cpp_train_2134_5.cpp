#include <bits/stdc++.h>
using namespace std;
struct think {
  int x;
  int y;
} a[100001];
int comp(const think &a, const think &b) {
  if (a.x < b.x)
    return a.x;
  else if (a.x == b.x) {
    if (a.x < b.x)
      return a.x;
    else if (b.x < a.x)
      return b.x;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m, a, b, c, d;
  bool okay;
  cin >> n >> m;
  cin >> a >> b >> c >> d;
  if (a <= n && c <= n) {
    if (b + d <= m) okay = true;
  }
  if (a <= n && d <= n) {
    if (b + c <= m) okay = true;
  }
  if (b <= n && c <= n) {
    if (a + d <= m) okay = true;
  }
  if (b <= n && d <= n) {
    if (a + c <= m) okay = true;
  }
  if (a <= m && c <= m) {
    if (b + d <= n) okay = true;
  }
  if (a <= m && d <= m) {
    if (b + c <= n) okay = true;
  }
  if (b <= m && c <= m) {
    if (a + d <= n) okay = true;
  }
  if (b <= m && d <= m) {
    if (a + c <= n) okay = true;
  }
  if (okay)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
