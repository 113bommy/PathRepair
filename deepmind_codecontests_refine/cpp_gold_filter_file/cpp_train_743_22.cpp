#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed;
  int n, k, m, t;
  cin >> n >> k >> m >> t;
  for (int i = 0; i < t; i++) {
    int type, cur;
    cin >> type >> cur;
    if (type) {
      if (k >= cur) {
        k++;
      }
      n++;
    } else {
      if (k > cur) {
        k -= cur;
        n -= cur;
      } else {
        n -= (n - cur);
      }
    }
    cout << n << " " << k << "\n";
  }
  return 0;
}
