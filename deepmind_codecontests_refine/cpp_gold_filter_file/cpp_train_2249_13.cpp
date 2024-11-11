#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int tp = 0, bt = n, lt = m, rt = 0, blacks = 0;
  for (int i = n; i > 0; i--) {
    string t;
    cin >> t;
    for (int j = 0; j < m; j++) {
      if (t[j] == 'B') {
        blacks++;
      }
      if (t[j] == 'B' && i > tp) {
        tp = i;
      }
      if (t[j] == 'B' && j + 1 > rt) {
        rt = j + 1;
      }
      if (t[j] == 'B' && i < bt) {
        bt = i;
      }
      if (t[j] == 'B' && j + 1 < lt) {
        lt = j + 1;
      }
    }
  }
  int f = max((tp - bt + 1), (rt - lt + 1));
  if (f > m || f > n) {
    cout << -1;
    return 0;
  }
  if (blacks == 0) {
    cout << 1;
    return 0;
  }
  cout << f * f - blacks;
}
