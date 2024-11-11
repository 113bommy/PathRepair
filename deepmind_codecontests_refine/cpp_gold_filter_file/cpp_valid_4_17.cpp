#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
void solve() {
  long long p;
  cin >> p;
  if (p == 5) {
    cout << "2 4\n";
    return;
  }
  p--;
  long long x = p / 2;
  p = p / x;
  cout << p << ' ' << x << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
}
