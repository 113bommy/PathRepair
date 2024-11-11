#include <bits/stdc++.h>
using namespace std;
int main() {
  int c, v, v1, a, l;
  cin >> c >> v >> v1 >> a >> l;
  int s = v;
  int ct = 1;
  while (s < c) {
    if (v + (ct * a) - l > v1)
      s += v1 - l;
    else {
      s += v + (ct * a) - l;
    }
    ct++;
  }
  cout << ct;
  return 0;
}
