#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int time = abs(a - c) + abs(b - d);
    if (a == c || b == d)
      cout << time << '\n';
    else
      cout << time + 2 << '\n';
  }
}
