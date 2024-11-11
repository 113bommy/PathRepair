#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e7;
const int MOD = (int)1e9 + 7;
const int inf = (int)5e8;
const long long infll = (long long)1e17;
void solve() {
  int n;
  cin >> n;
  string s = to_string(n);
  if (s.back() <= '5') {
    s.back() = 0;
    cout << s << endl;
  } else {
    n += 10 - s.back() + '0';
    cout << to_string(n) << endl;
  }
}
int main() {
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
