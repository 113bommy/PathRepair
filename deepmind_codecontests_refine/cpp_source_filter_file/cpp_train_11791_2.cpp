#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin.exceptions(cin.failbit);
  long long n;
  cin >> n;
  vector<int> cs(10, 1);
  long long p = 1;
  int ix = 0;
  while (p <= n) {
    p /= cs[ix];
    cs[ix]++;
    p *= cs[ix];
    ix = (ix + 1) % 10;
  }
  string cf = "codeforces";
  for (int i = (0); i < (10); ++i) {
    for (int _ = (0); _ < (cs[i]); ++_) cout << cf[i];
  }
  cout << endl;
}
