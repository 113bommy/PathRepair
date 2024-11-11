#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, i, m = 0, mx = 1, f = 0, maxx;
    cin >> n;
    set<long long int> s;
    long long int a[n], b[n];
    for (i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] < i + 1) f = 1;
    }
    if (f)
      cout << -1;
    else {
      for (i = 0; i < n; i++) {
        if (a[i] > m) {
          cout << a[i] << ' ';
          m = a[i];
          s.insert(a[i]);
        } else {
          cout << mx << ' ';
          s.insert(a[i]);
          mx++;
        }
        while (s.find(mx) != s.end()) mx++;
      }
    }
    cout << '\n';
  }
  return 0;
}
