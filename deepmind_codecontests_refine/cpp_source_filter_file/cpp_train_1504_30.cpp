#include <bits/stdc++.h>
using namespace std;
void maximize(int &a, int b) { a = std::max(a, b); }
void minimize(int &a, int b) { a = std::min(a, b); }
int main() {
  int mx = 2 * 1000 * 1000 * 1000;
  int mn = -mx;
  int n;
  cin >> n;
  while (n-- > 0) {
    string s;
    cin >> s;
    int x;
    cin >> x;
    string ans;
    cin >> ans;
    if (ans == "N") {
      if (s == ">")
        s = "<=";
      else if (s == "<")
        s = ">=";
      else if (s == ">=")
        s = "<";
      else
        s = ">";
    }
    if (s == ">")
      maximize(mn, x + 1);
    else if (s == ">=")
      maximize(mn, x);
    else if (s == "<")
      minimize(mx, x - 1);
    else
      minimize(mx, x);
  }
  if (mn <= mx)
    cout << mn;
  else
    cout << "impossible";
  return 0;
}
