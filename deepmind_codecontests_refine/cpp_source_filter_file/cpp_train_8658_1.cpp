#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, l, r;
  cin >> n >> l >> r;
  int s = 0;
  for (int i = 0; i < n; i++) {
    if (i < l)
      s += 1 << i;
    else
      s += 1;
  }
  cout << s << ' ';
  s = 0;
  for (int i = 0; i < n; i++) {
    if (i < r)
      s += 1 << i;
    else
      s += 1 << (l - 1);
  }
  cout << s;
  return 0;
}
