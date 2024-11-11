#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long x, c = 0;
    stack<long long> s;
    for (long long i = 0; i < n; i++) {
      cin >> x;
      if (s.empty() || x >= s.top()) s.push(x);
      if (x < s.top()) {
        while (x < s.top()) {
          s.pop();
          c++;
          if (s.empty()) break;
        }
        s.push(x);
      }
    }
    cout << c << "\n";
  }
  return 0;
}
