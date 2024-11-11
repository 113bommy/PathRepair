#include <bits/stdc++.h>
const double EPS = 1e-6;
const int INF = 0x3fffffff;
const long long LINF = INF * 1ll * INF;
const double PI = acos(-1.0);
using namespace std;
int main() {
  long long a, b, c;
  cin >> a >> b >> c;
  long long ans = ((b + c - 1) % a + a) % a + 1;
  cout << ans << endl;
  return 0;
}
