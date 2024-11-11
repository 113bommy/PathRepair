#include <bits/stdc++.h>
using namespace std;
int Count(int a) {
  int l = 0;
  if (a / 10 == 0) {
    return 1;
  }
  while (a / 10) {
    l += 1;
    a /= 10;
  }
  return l;
}
int main() {
  int n = 0, a = 0, b = 0, c = 0, p = -1;
  cin >> a >> b >> c;
  int ans = 1;
  int bl = Count(b);
  for (int i = 1; i <= 9; i++) {
    int u = Count(a);
    if (u + 1 <= bl) a *= 10;
    if (a < b && u == bl) a *= 10;
    int h = a / b;
    if (h == c) {
      p = i;
      break;
    }
    a -= b * h;
  }
  cout << p << endl;
  return 0;
}
