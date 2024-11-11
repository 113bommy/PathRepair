#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  cout << "YES\n";
  for (int i = 0; i < n; ++i) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    a = abs(a), b = abs(b);
    cout << 1 + 2 * (a % 2) + (b % 2) << "\n";
  }
}
