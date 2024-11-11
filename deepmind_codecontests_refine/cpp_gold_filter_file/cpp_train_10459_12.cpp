#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 200006;
const long long INF = 1e18;
map<pair<int, int>, int> h;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long a, b;
  cin >> a >> b;
  if (a == b) {
    cout << "infinity\n";
    return 0;
  }
  long long ini = a;
  a -= b;
  long long ans = 0;
  for (long long d = 1; d * d <= a; d++) {
    if (a % d == 0) {
      long long oth = a / d;
      if (d * (oth + 1) > ini) {
        ans++;
      }
      if (oth != d && oth * (d + 1) > ini) {
        ans++;
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
