#include <bits/stdc++.h>
using namespace ::std;
int main() {
  int n, m, ik;
  string s, t;
  cin >> n >> m >> s >> t;
  int k = m;
  vector<int> ipos(n + 2);
  vector<int> pos(n + 2);
  for (int i = 0; i <= m - n; i++) {
    ik = 0;
    for (int ii = i; ii <= i + n - 1; ii++) {
      if (!(s[ii - i] == t[ii])) {
        ik++;
        ipos[ik] = ii - i + 1;
      }
    }
    if (ik < k) {
      k = ik;
      pos = ipos;
    }
  }
  cout << k << '\n';
  for (int i = 1; i <= k; i++) cout << pos[i] << " ";
}
