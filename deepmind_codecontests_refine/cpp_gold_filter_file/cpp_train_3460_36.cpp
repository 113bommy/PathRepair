#include <bits/stdc++.h>
using namespace std;
int main() {
  ios ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int y = max(c - a + 1, b);
    cout << a << " " << y << " " << c << '\n';
  }
  return 0;
}
