#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, x, y;
    cin >> n >> x >> y;
    int a = x + y - n + 1;
    if (a >= n)
      cout << n << " ";
    else if (a <= 0)
      cout << 1 << " ";
    else
      cout << a << " ";
    if (x + y > n)
      cout << n << endl;
    else
      cout << x + y - 1 << endl;
  }
}
