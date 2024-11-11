#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  int res = 0;
  for (int i = 1; i < n; i++) {
    if ((n - i) % i == 0) {
      res++;
    }
  }
  cout << res << endl;
}
int main() {
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
