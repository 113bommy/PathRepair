#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<pair<int, int> > v;
  for (int i = 1; i <= n - 1; ++i) {
    int a, b;
    cin >> a >> b;
    v.push_back(make_pair(a, b));
  }
  int c[n + 1];
  for (int i = 1; i <= n; ++i) cin >> c[i];
  int a = -1, b = -1, ans = -1;
  for (int i = 0; i < n - 1; ++i) {
    int p = v[i].first;
    int q = v[i].second;
    if (c[p] != c[q]) {
      if (a == -1 && b == -1) {
        a = p;
        b = q;
      } else if (ans == -1) {
        if (p == a || p == b)
          ans = p;
        else if (q == a || q == b)
          ans = q;
        else {
          cout << "NO\n";
          return 0;
        }
      } else {
        if (p != ans && q != ans) {
          cout << "NO\n";
          return 0;
        }
      }
    }
  }
  cout << "YES\n";
  if (ans == -1)
    cout << a << endl;
  else
    cout << ans << endl;
}
