#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s, a, b;
  cin >> s >> a >> b;
  string c = s;
  reverse(c.begin(), c.end());
  int x = s.size(), y = a.size(), z = b.size();
  int q = s.find(a);
  int w = c.find(a);
  int e = s.find(b, q + y);
  int r = c.find(b, q + y);
  if (q >= 0 && w >= 0 && e >= 0 && r >= 0)
    cout << "both";
  else if (q >= 0 && e >= 0)
    cout << "forward";
  else if (w >= 0 && r >= 0)
    cout << "backward";
  else
    cout << "fantasy";
  return 0;
}
