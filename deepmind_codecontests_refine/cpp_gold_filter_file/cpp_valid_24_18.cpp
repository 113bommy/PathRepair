#include <bits/stdc++.h>
using namespace std;
void solve() {
  int a;
  cin >> a;
  if (a % 10 == 9) {
    cout << a / 10 + 1 << endl;
    return;
  }
  cout << a / 10 << endl;
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
