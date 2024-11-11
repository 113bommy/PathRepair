#include <bits/stdc++.h>
using namespace std;
int nxt() {
  int a;
  cin >> a;
  return a;
}
long long int nxtll() {
  long long int a;
  cin >> a;
  return a;
}
void solve() {
  int n = nxt();
  if (n <= 2)
    cout << n << endl;
  else
    cout << n - 1 << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  bool multi_run = 1;
  if (multi_run) {
    int t;
    cin >> t;
    while (t--) solve();
  } else {
    solve();
  }
}
