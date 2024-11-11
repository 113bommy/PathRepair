#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, k, m, t;
  cin >> n >> k >> m >> t;
  int d = n, p = k;
  for (int i = 0; i < t; i++) {
    int type, pos;
    cin >> type >> pos;
    if (type) {
      d++;
      if (pos <= p) {
        p++;
      }
    } else {
      if (pos < p) {
        d -= pos;
        p -= pos;
      } else
        d = pos;
    }
    cout << d << ' ' << p << '\n';
  }
}
