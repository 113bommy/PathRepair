#include <bits/stdc++.h>
using namespace std;
int n, x, y, l, r, s, s1, d;
int main() {
  cin >> n >> x >> y;
  l = x - 1, r = y - 1;
  d = min(l, r);
  l -= d, r -= d;
  s += d + max(l, r);
  l = n - x, r = n - y;
  d = min(l, r);
  l -= d, r -= d;
  s1 += d + max(l, r);
  if (s <= s1)
    cout << "White";
  else
    cout << "Black";
}
