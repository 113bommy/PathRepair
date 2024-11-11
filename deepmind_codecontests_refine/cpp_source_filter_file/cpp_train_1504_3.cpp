#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string o;
  int x;
  char a;
  int l = -1000000000, h = 1000000000;
  while (n--) {
    cin >> o >> x >> a;
    if (a == 'Y') {
      if (o == ">") {
        l = max(l, x + 1);
      }
      if (o == ">=") {
        l = max(l, x);
      }
      if (o == "<") {
        h = min(h, x - 1);
      }
      if (o == "<=") {
        h = min(h, x);
      }
    } else {
      if (o == "<") {
        l = max(l, x);
      }
      if (o == "<=") {
        l = max(l, x + 1);
      }
      if (o == ">") {
        h = min(h, x);
      }
      if (o == ">=") {
        h = min(h, x - 1);
      }
    }
  }
  if (l > h)
    cout << "Impossible" << endl;
  else
    cout << l << endl;
  return 0;
}
