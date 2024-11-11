#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m, e1 = 0, o1 = 0, e2 = 0, o2 = 0, hold;
  cin >> n;
  vector<long long> ar(n);
  for (long long i = 0; i < n; i++) {
    cin >> ar[i];
    if (ar[i] % 2 == 0)
      e1++;
    else
      o1++;
  }
  cin >> m;
  vector<long long> ar1(m);
  for (long long i = 0; i < m; i++) {
    cin >> ar1[i];
    if (ar1[i] % 2 == 0)
      e2++;
    else
      o2++;
  }
  cout << e1 * e2 + o1 * o2 << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long q = 1;
  cin >> q;
  while (q--) {
    solve();
  }
  return 0;
}
