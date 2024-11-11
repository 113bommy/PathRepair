#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  long double A;
  map<pair<int, int>, int> MA;
  long ans = 0;
  while (cin >> A) {
    long a = A * 1e9 + 0.5;
    int x = 0, y = 0;
    while (a % 2 == 0) a /= 2, x++;
    while (a % 5 == 0) a /= 5, y++;
    x = min(18, x);
    y = min(18, y);
    for (auto [a, b] : MA) {
      if (x + a.first >= 18 && y + a.second >= 18) ans += b;
    }
    MA[{x, y}]++;
  }
  cout << ans << "\n";
}
