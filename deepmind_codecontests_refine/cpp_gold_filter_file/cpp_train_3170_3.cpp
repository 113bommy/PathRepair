#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, t, v;
  int n, c = 1, l = 0;
  cin >> n;
  cin >> s;
  n = n - 1;
  while (n--) {
    cin >> t;
    if (s == t)
      c++;
    else {
      l++;
      v = t;
    }
  }
  if (c > l)
    cout << s << endl;
  else
    cout << v << endl;
}
