#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
  int a, b, x, y;
  cin >> a >> b >> x >> y;
  cout << min(abs(a - x), abs(b - y)) << endl;
  return 0;
}
