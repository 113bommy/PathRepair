#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const double PI = 3.141592653589793238463;
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int q;
  cin >> q;
  while (q--) {
    long long sum = 0, r = 0;
    long long x, y;
    cin >> x;
    for (int i = 1; i <= x; i++) {
      cin >> y;
      sum += y;
      r ^= y;
    }
    cout << "2\n" << r << " " << sum + r << '\n';
  }
  return 0;
}
