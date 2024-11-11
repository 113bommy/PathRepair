#include <bits/stdc++.h>
using namespace std;
long long int mod = 1e9 + 7;
int I_INF = 2e9;
long long int L_INF = 1e18;
void solve() {
  long long int n, i, j, l, r, index, ctr, num;
  cin >> n >> l >> r;
  vector<long long int> vect(n, 0);
  vect[0] = 2 * (n - 1);
  for (i = 1; i < n; i++) {
    vect[i] = 2 * (n - 1 - i);
    vect[i] += vect[i - 1];
  }
  vect[n - 1]++;
  index =
      (long long int)(lower_bound(vect.begin(), vect.end(), l) - vect.begin());
  ctr = (index > 1) ? vect[index - 1] : 0;
  while (ctr < r) {
    if (index == (n - 1)) {
      ctr++;
      if (ctr >= l && ctr <= r) cout << 1 << " ";
    } else {
      for (i = index + 1; i < n; i++) {
        ctr++;
        num = index + 1;
        if (ctr >= l && ctr <= r) cout << num << " ";
        ctr++;
        num = i + 1;
        if (ctr >= l && ctr <= r) cout << num << " ";
      }
    }
    index++;
  }
  cout << endl;
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
