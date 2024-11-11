#include <bits/stdc++.h>
using namespace std;
void sol() {
  long long int a, b, r, c, res = 0, t;
  cin >> a >> b >> c >> r;
  if (c - r <= min(a, b) && (c + r) >= max(a, b))
    cout << "0\n";
  else if ((c + r) < min(a, b) || r == 0 || c - max(a, b) > r) {
    cout << abs(a - b) << endl;
  } else if (c - r <= min(a, b)) {
    res = max(a, b) - (c + r);
    cout << res << endl;
  } else if ((c + r) >= max(a, b)) {
    res = c - r - min(a, b);
    cout << res << endl;
  } else {
    res = c - r - min(a, b) + (max(a, b) - (c + r));
    cout << res << endl;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  while (t--) sol();
  return 0;
  ;
}
