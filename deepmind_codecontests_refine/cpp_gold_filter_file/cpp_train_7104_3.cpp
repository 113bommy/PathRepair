#include <bits/stdc++.h>
using namespace std;
void make_unique(vector<long long> vec) {
  sort((vec).begin(), (vec).end());
  vec.resize(unique((vec).begin(), (vec).end()) - vec.begin());
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t = 1;
  cin >> t;
  while (t--) {
    long long q, k, h, m, i, x, j, flag = 0, count = 0, move = 0;
    long long n0, n1, n2;
    cin >> n0 >> n1 >> n2;
    if (n1 != 0) {
      string zeone;
      for (i = 1; i <= n1 + 1; i++) {
        if (i & 1)
          zeone += '1';
        else
          zeone += '0';
      }
      string zeze(n0, '0');
      string oneone(n2, '1');
      zeone.insert(2, zeze);
      zeone.insert(1, oneone);
      cout << zeone;
    } else if (n1 == 0) {
      if (n0 != 0)
        cout << string(n0 + 1, '0');
      else
        cout << string(n2 + 1, '1');
    }
    cout << '\n';
  }
  return 0;
}
