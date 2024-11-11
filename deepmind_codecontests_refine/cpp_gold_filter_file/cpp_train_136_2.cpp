#include <bits/stdc++.h>
using namespace std;
bool isV(char ch) {
  return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}
bool f(int t, int a, int b, int c) {
  for (int t0 = t; t0 <= c + t; t0++) {
    int dneed = (t0 - t) * a;
    int dr = t0 * b;
    if (dr < dneed) return false;
  }
  return true;
}
void tc() {
  int a, b, c;
  cin >> a >> b >> c;
  int l = 0, hi = a * c, mid, ans;
  while (l <= hi) {
    mid = l + (hi - l) / 2;
    if (f(mid, a, b, c) == true) {
      ans = mid;
      hi = mid - 1;
    } else
      l = mid + 1;
  }
  cout << ans;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  tc();
  return 0;
}
