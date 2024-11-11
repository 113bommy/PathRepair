#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n, m;
    cin >> n >> m;
    long long int s = 0, x, y, i, j;
    vector<long long int> a, b;
    for (i = 0; i < n; i++) {
      cin >> x;
      if (x < 0)
        a.push_back(x);
      else
        b.push_back(x);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if (a.size() > 0 && b.size() > 0) {
      if (abs(a[0]) > b[b.size() - 1]) {
        s += abs(a[0]);
        for (i = m; i < a.size(); i += m) s += abs(2 * a[i]);
        for (i = b.size() - 1; i >= 0; i -= m) s += (2 * b[i]);
      } else {
        s += b[b.size() - 1];
        for (i = b.size() - 1 - m; i >= 0; i -= m) s += (2 * b[i]);
        for (i = 0; i < a.size(); i += m) s += abs(2 * a[i]);
      }
    } else if (a.size() > 0) {
      s += abs(a[0]);
      for (i = m; i < a.size(); i += m) s += abs(2 * a[i]);
    } else {
      s += b[b.size() - 1];
      for (i = b.size() - 1 - m; i >= 0; i -= m) s += (2 * b[i]);
    }
    cout << s << endl;
  }
  return 0;
}
