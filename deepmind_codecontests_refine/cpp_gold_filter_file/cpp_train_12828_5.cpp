#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long n, x, y;
    cin >> n >> x >> y;
    cout << max(min((x - n + y + 1), n), (long long)1) << " ";
    long long equalplaces = (min(x, n - y) + min(y, n - x));
    equalplaces -= 1;
    if (x + y >= n + 1)
      cout << n;
    else
      cout << equalplaces;
    cout << endl;
  }
  return 0;
}
