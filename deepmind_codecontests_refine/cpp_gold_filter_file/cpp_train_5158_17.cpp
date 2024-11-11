#include <bits/stdc++.h>
using namespace std;
int hm(int a) {}
int main() {
  int x, y, t, a;
  cin >> x >> y;
  if (x < y) {
    t = x;
    x = y;
    y = t;
  }
  long long ans = 0;
  a = ((x + y) / 5) * 5;
  while (a) {
    if (x >= a) {
      x = a - 1;
    }
    ans += (x - max((a - y), 1) + 1);
    a -= 5;
  }
  cout << ans;
}
