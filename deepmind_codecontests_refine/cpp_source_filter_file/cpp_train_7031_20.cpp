#include <bits/stdc++.h>
using namespace std;
int main() {
  int p1, p2, p3, p4, a, b;
  cin >> p1 >> p2 >> p3 >> p4 >> a >> b;
  int m = min(min(min(p1, p2), p3), p4);
  cout << max(0, min(b, m) - a) << endl;
  return 0;
}
