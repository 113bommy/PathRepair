#include <bits/stdc++.h>
using namespace std;
int main() {
  int p[4], a, b;
  cin >> p[0] >> p[1] >> p[2] >> p[3] >> a >> b;
  sort(p, p + 4);
  cout << max(0, min(b, p[0]) - a) << endl;
  return 0;
}
