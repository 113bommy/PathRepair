#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  string c, a, b;
  cin >> c >> a >> b;
  int d = c.find(a), e = c.rfind(b);
  bool f = d != string::npos && e != string::npos && e >= d + a.size();
  reverse(begin(c), end(c));
  d = c.find(a), e = c.rfind(b);
  bool k = d != string::npos && e != string::npos && e >= d + a.size();
  if (f && k)
    cout << "both";
  else if (f)
    cout << "forward";
  else if (k)
    cout << "backward";
  else
    cout << "fantasy";
  return 0;
}
