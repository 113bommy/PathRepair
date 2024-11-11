#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  string s = "";
  cin >> n;
  for (int i = 1; i <= n; i++) {
    if (i % 2 != 0) {
      if (i != n)
        s += "I hate that ";
      else
        s += "I hate it";
    } else {
      if (i != n)
        s += "I love that ";
      else
        s += "i love it";
    }
  }
  cout << s << endl;
}
