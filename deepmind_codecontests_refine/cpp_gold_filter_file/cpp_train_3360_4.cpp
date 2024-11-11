#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll mod = 1e9 + 7;
const ll mxr = 1e6 + 10;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, x, les = 0, mor = 0, sem = 0, dif;
    cin >> n >> x;
    int ar[n];
    for (int i = 0; i < n; i++) {
      cin >> ar[i];
      if (ar[i] < x)
        les += (x - ar[i]);
      else if (ar[i] > x)
        mor += (ar[i] - x);
      else
        sem++;
    }
    if (les == 0 && mor == 0)
      cout << 0 << "\n";
    else if (les == mor || sem > 0)
      cout << 1 << "\n";
    else
      cout << 2 << "\n";
  }
  return 0;
}
