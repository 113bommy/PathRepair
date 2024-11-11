#include <bits/stdc++.h>
using namespace std;
int p1, p2, p3, p4, a, b;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> p1 >> p2 >> p3 >> p4 >> a >> b;
  int p = min(min(p1, p2), min(p3, p4));
  if (p > b)
    cout << b - a + 1;
  else
    cout << max(p - a, 0);
  return 0;
}
