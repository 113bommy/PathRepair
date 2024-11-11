#include <bits/stdc++.h>
using namespace std;
int a, b, c, d, e, f;
int main() {
  srand(time(NULL));
  ios_base::sync_with_stdio(false);
  cin >> a >> b;
  cin >> c >> d;
  cin >> e >> f;
  if (a == c && c == e) {
    cout << "1\n";
    return 0;
  }
  if (b == d && d == f) {
    cout << "1\n";
    return 0;
  }
  if ((a == c && (f >= max(b, d) || f <= min(b, d))) ||
      (a == e && (d >= max(b, f) || f <= min(b, f))) ||
      (e == c && (b >= max(f, d) || b <= min(f, d))) ||
      (b == d && (e >= max(a, c) || e <= min(a, c))) ||
      (b == f && (c >= max(a, e) || c <= min(a, e))) ||
      (d == f && (a >= max(c, e) || a <= min(c, e)))) {
    cout << "2\n";
    return 0;
  }
  cout << "3\n";
  return 0;
}
