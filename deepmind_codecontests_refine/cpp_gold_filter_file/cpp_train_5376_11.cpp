#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, m;
  cin >> n;
  cin >> m;
  if (n > 27)
    cout << m << endl;
  else {
    cout << m % (1 << n) << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  int t = 1;
  while (t--) {
    solve();
  }
}
