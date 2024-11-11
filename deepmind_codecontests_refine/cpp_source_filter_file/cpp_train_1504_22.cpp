#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j;
  cin >> n;
  int l = -1e9, r = 1e9;
  string a = "<", b = "<=", cs = ">", d = ">=";
  while (n--) {
    string s;
    char c;
    int num;
    cin >> s >> num >> c;
    if (s == a) {
      if (c == 'Y')
        r = min(r, num - 1);
      else
        l = max(num, l);
    } else if (s == b) {
      if (c == 'Y')
        r = min(r, num);
      else
        l = max(l, num + 1);
    } else if (s == cs) {
      if (c == 'Y')
        l = max(num + 1, l);
      else
        r = min(r, num);
    } else {
      if (c == 'Y')
        l = max(num, l);
      else
        r = min(num - 1, r);
    }
  }
  if (r < l)
    cout << "Impossible";
  else
    cout << l << " ";
}
