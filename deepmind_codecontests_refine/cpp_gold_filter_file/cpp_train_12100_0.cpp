#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long int x, y, a, b;
    cin >> x >> y >> a >> b;
    long long int t = (y - x) / (a + b);
    if ((y - x) % (a + b) == 0) {
      cout << t;
    } else
      cout << "-1";
    cout << endl;
  }
}
