#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  long long n, a, b, c, d;
  cout << "YES\n";
  cin >> n;
  while (n--) {
    cin >> a >> b >> c >> d;
    cout << (c % 2) + 1 + 2 * (d % 2) << "\n";
  }
}
