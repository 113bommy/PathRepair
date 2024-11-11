#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t > 0) {
    int n, m;
    cin >> n >> m;
    int k = 0;
    while (n > 0) {
      int a, b, c, d;
      cin >> a >> b >> c >> d;
      if (a == d) {
        k = 1;
      }
      n--;
    }
    if (k == 0 || m % 2 == 1)
      cout << "NO\n";
    else
      cout << "YES\n";
    t--;
  }
}
