#include <bits/stdc++.h>
using namespace std;
long long n, h, a, b, k;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> h >> a >> b >> k;
  for (int i = 0; i < k; i++) {
    int t1, f1, t2, f2;
    cin >> t1 >> f1 >> t2 >> f2;
    if (t1 == t2) {
      cout << abs(f2 - f1);
    } else if (f1 > b && f2 > b) {
      cout << abs(f2 - b) + abs(f1 - b) + abs(t2 - t1) << '\n';
    } else if (f1 < a && f2 < a) {
      cout << abs(a - f1) + abs(t2 - t1) + abs(a - f2) << '\n';
    } else {
      cout << abs(f2 - f1) + abs(t2 - t1) << '\n';
    }
  }
  return 0;
}
