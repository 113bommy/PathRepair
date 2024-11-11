#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long a, b, n;
  cin >> a >> b >> n;
  if (!a) {
    if (!b)
      cout << 1 << '\n';
    else
      cout << "No solution" << '\n';
    return 0;
  }
  if (!b) {
    cout << 0 << '\n';
    return 0;
  }
  if (b % a) {
    cout << "No solution" << '\n';
    return 0;
  }
  b /= a;
  for (long long l = -1000; l < 1001; l++) {
    long long at = 1;
    int cnt = 0;
    while (abs(at) <= abs(b) && cnt < n) at *= l, cnt++;
    if (at == b && cnt == n) {
      cout << l << '\n';
      return 0;
    }
  }
  cout << "No solution" << '\n';
  return 0;
}
