#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int a, b;
    cin >> a >> b;
    long long int mx = max(a, b);
    long long int mn = min(a, b);
    long long int diff = mx - mn;
    if (mn == mx)
      cout << 0 << endl;
    else if (diff == 1)
      cout << 1 << endl;
    else if (diff == 2)
      cout << 3 << endl;
    else {
      long long int i = 0;
      long long int res = 1;
      while (res < diff) {
        i++;
        res = i * (i + 1) * 1ll;
        res /= 2;
      }
      while (diff % 2 != res % 2) {
        i++;
        res = i * (i + 1) * 1ll;
        res /= 2;
      }
      cout << i << endl;
    }
  }
}
