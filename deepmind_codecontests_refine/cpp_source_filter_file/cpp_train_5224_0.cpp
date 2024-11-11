#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  vector<long long> x(10, 0);
  string s;
  cin >> s;
  for (long long i = 0; i < n; i++) {
    if (s[i] == 'L') {
      for (long long i = 0; i < 9; i++) {
        if (x[i] == 0) {
          x[i] = 1;
          break;
        }
      }
    } else if (s[i] == 'R') {
      for (long long i = 9; i >= 0; i--) {
        if (x[i] == 0) {
          x[i] = 1;
          break;
        }
      }
    } else {
      x[s[i] - '0'] = 0;
    }
  }
  for (long long i = 0; i < 10; i++) cout << x[i];
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
