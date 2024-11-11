#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, d, m;
  while (cin >> n >> d) {
    vector<int> a(n);
    for (int i = 0; i < n; cin >> a[i++])
      ;
    sort(a.begin(), a.end());
    int r = 0;
    cin >> m;
    for (int i = 0; i < min(n, m); i++) {
      r += a[i];
    }
    r -= (m - n) * d;
    cout << r << endl;
  }
  return 0;
}
