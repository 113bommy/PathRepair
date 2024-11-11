#include <bits/stdc++.h>
using namespace std;
int main() {
  int p1, p2, p3, p4, a, b;
  cin >> p1 >> p2 >> p3 >> p4 >> a >> b;
  p1 = min(p1, min(p2, min(p3, p4)));
  cout << max(0, min(p1, b + 1) - a);
  return 0;
}
