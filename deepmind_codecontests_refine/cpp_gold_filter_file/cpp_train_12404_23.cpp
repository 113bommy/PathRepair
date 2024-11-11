#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, r, s[2000], b[2000];
  cin >> n >> m >> r;
  int t1 = INT_MAX, t2 = 0, ss, bb;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    if (s[i] < t1) {
      ss = s[i];
      t1 = s[i];
    }
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
    if (b[i] > t2) {
      bb = b[i];
      t2 = b[i];
    }
  }
  int d, c;
  d = r % ss;
  c = (r - d) / ss;
  int rou = (c * bb) + d;
  if (rou < r)
    cout << r << endl;
  else
    cout << rou << endl;
  return 0;
}
