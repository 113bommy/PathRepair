#include <bits/stdc++.h>
using namespace std;
int ch(int x);
int fun(int x, int y, int p, int a, int vb, int vs);
int i;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, x, lo = -1000, up = 1001, t1, t2;
  cin >> n >> x;
  for (int i = 0; i < n; i++) {
    int n1, n2;
    cin >> n1 >> n2;
    int mi = min(n1, n2);
    int ma = max(n1, n2);
    if (i >= 1) {
      if (t2 < mi || ma < t1) {
        cout << -1;
        return 0;
      }
    }
    lo = max(lo, mi);
    up = min(up, ma);
    t1 = lo;
    t2 = up;
  }
  if (x >= lo && x <= up) {
    cout << 0;
    return 0;
  }
  cout << min(abs(x - lo), abs(x - up));
  return 0;
}
