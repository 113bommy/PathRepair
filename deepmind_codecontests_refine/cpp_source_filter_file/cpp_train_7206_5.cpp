#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long a, b, x, y;
    cin >> a >> b >> x >> y;
    x++;
    y++;
    cout << max(max((a - x) * (y), a * (b - y)), max((x - 1) * b, (y - 1) * a))
         << endl;
  }
}
