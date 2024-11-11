#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long a, b;
    cin >> a >> b;
    long long d = abs(b - a);
    cout << (d / 10 + (d % 10 == 0 ? 0 : 1)) << "\n";
  }
  return 0;
}
