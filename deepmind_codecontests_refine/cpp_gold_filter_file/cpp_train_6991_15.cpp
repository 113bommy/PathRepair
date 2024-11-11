#include <bits/stdc++.h>
using namespace std;
template <typename T>
string toString(T val) {
  ostringstream oss;
  oss << val;
  return oss.str();
}
using ldd = long double;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long a, b, c;
  cin >> a >> b >> c;
  long long gg = a - b;
  if (c == 0) {
    if (gg > 0)
      cout << '+';
    else if (gg < 0)
      cout << '-';
    else
      cout << '0';
    return 0;
  }
  if (gg - c <= 0 && gg + c >= 0) {
    cout << "?";
    return 0;
  }
  if (gg + c < 0 && gg - c > 0) {
    cout << "?";
    return 0;
  }
  if (gg - c > 0) {
    cout << '+';
    return 0;
  }
  if (gg + c < 0) {
    cout << '-';
    return 0;
  }
  return 0;
}
