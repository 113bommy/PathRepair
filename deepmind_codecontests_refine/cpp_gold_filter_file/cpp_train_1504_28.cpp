#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, num, l, r;
  string str, res;
  cin >> n;
  l = 1e9;
  l = l * (-2);
  r = 1e9;
  r = r * (2);
  while (n--) {
    cin >> str >> num >> res;
    if (res == "N") {
      if (str == ">=")
        str = "<";
      else if (str == ">")
        str = "<=";
      else if (str == "<")
        str = ">=";
      else if (str == "<=")
        str = ">";
    }
    if (str == ">=")
      l = max(l, num);
    else if (str == ">")
      l = max(l, num + 1);
    else if (str == "<=")
      r = min(r, num);
    else if (str == "<")
      r = min(r, num - 1);
  }
  if (l > r)
    cout << "Impossible";
  else
    cout << l;
  return 0;
}
