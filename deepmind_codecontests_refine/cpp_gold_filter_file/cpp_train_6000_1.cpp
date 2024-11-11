#include <bits/stdc++.h>
using namespace std;
template <typename T>
using V = vector<T>;
template <typename T>
using VV = vector<V<T>>;
template <typename T>
istream& operator>>(istream& cin, V<T>& arr) {
  for (T& val : arr) {
    cin >> val;
  }
  return cin;
}
template <typename T>
ostream& operator<<(ostream& cout, V<T>& arr) {
  for (T& val : arr) {
    cout << val << " ";
  }
  return cout;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout.precision(10);
  long long x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  long long p1, p2, p3, p4;
  p1 = abs(y1 - (y2 - 1)) + abs(x1 - (x2 - 1));
  p2 = abs(y1 - (y2 + 1)) + abs(x1 - (x2 - 1));
  p3 = abs(y1 - (y2 + 1)) + abs(x1 - (x2 + 1));
  p4 = abs(y1 - (y2 - 1)) + abs(x1 - (x2 + 1));
  long long ans = p1 + p2;
  ans = min(ans, p2 + p3);
  ans = min(ans, p3 + p4);
  ans = min(ans, p4 + p1);
  ans += 6;
  cout << ans;
  return 0;
}
