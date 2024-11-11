#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d, k;
  int t;
  cin >> t;
  while (t--) {
    cin >> a >> b >> c >> d;
    int v1 = ceil(a / (double)c);
    int v2 = ceil(b / (double)d);
    if (v1 + v2 <= k) {
      cout << v1 << " " << v2 << endl;
    } else {
      cout << "-1" << endl;
    }
  }
  return 0;
}
