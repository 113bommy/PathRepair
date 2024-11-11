#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, ss[1000];
  int n, i, j, k, l;
  cin >> s >> n;
  for (i = 0; i < n; i++) {
    cin >> ss[i];
  }
  sort(ss, ss + n);
  string x = *lower_bound(ss, ss + n, s);
  if (x.substr(0, s.size()) == s) {
    cout << x;
    return 0;
  }
  cout << s;
  return 0;
}
