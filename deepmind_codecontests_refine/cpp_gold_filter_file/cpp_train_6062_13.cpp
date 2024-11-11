#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    int n, m, maxi = 0;
    cin >> n >> m;
    int a[n];
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      if (i == 0) continue;
      maxi += (a[i]);
    }
    cout << min(m, maxi + a[0]) << '\n';
  }
  return 0;
}
