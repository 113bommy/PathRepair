#include <bits/stdc++.h>
using namespace std;
int i, j;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long a, b, c;
    cin >> a >> b >> c;
    if (c <= a) {
      cout << -1 << " ";
    } else
      cout << 1 << " ";
    int x = 1000000000 / b;
    if (c * x < a * b * x)
      cout << b * x << '\n';
    else
      cout << -1 << '\n';
  }
}
