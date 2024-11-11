#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, x;
    cin >> n >> x;
    int od = 0, ev = 0;
    for (int i = 0; i < n; i++) {
      int tmp;
      cin >> tmp;
      if (tmp % 2)
        od++;
      else
        ev++;
    }
    if (od and (x <= ev or (x - ev) % 2 or ev and x < n))
      cout << "Yes" << '\n';
    else
      cout << "No" << '\n';
  }
}
