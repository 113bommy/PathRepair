#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int a = 0, b = 0;
  int n, d, t;
  cin >> n >> d;
  int sol = 0;
  for (int i = 0; i < n; ++i) {
    cin >> t;
    if (t == 0) {
      if (b + t < 0) {
        a = 0;
        b = t;
        sol++;
      } else {
        a = max(0, a);
      }
    } else if (a + t > d) {
      sol = -1;
      break;
    }
    a = min(d, a + t);
    b = min(d, b + t);
  }
  cout << sol;
  return 0;
}
