#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, a, b, c = 0;
  cin >> n >> x;
  while (n--) {
    cin >> a >> b;
    if (x == a || x == b || x == 7 - a || x == 7 - b) c++;
    x = 7 - x;
  }
  if (c > 0)
    cout << "NO" << endl;
  else
    cout << "YES" << endl;
  return 0;
}
