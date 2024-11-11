#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t, n;
  cin >> t;
  for (int j = 0; j < t; j++) {
    cin >> n;
    vector<int> l(n);
    vector<int> r(n);
    for (int i = 0; i < n; i++) {
      cin >> l[i];
      cin >> r[i];
    }
    sort(l.begin(), l.end());
    sort(r.begin(), r.end());
    if (l[n - 1] - r[0] >= 0)
      cout << l[n - 1] - r[0] << "\n";
    else
      cout << 0;
  }
}
