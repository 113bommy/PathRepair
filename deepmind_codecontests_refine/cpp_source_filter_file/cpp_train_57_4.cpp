#include <bits/stdc++.h>
using namespace std;
const int inf = (int)1e9;
const int mod = inf + 7;
const double eps = 1e-9;
const double pi = acos(-1.0);
string second, t, x, y;
int n;
int main() {
  cin >> second >> t;
  string cur1 = second, cur2 = t;
  cin >> n;
  cout << second << " " << t;
  for (int i = 0; i < n; ++i) {
    cin >> x >> y;
    if (cur1 == x)
      cur1 = y;
    else if (cur2 == x)
      cur2 = y;
    cout << cur1 << " " << cur2 << endl;
  }
  return 0;
}
