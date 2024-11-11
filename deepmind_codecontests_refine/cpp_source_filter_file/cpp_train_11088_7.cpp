#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string a;
  cin >> a;
  if (a.size() == 1) {
    return cout << 1, 0;
  }
  char f = a[0], s = !(a[0] - '0') + '0';
  bool b = true, find = false;
  int c = 0;
  for (int i = 1; i < n; i++) {
    if (a[i] != a[i - 1]) c++;
  }
  cout << min(c + 2, n);
  return 0;
}
