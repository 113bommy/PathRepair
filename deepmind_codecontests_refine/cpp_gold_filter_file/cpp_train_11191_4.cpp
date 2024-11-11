#include <bits/stdc++.h>
using namespace std;
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(12) << fixed;
}
void solve() {
  long long a, b;
  cin >> a >> b;
  if (b > a) {
    {
      cout << -1 << "\n";
      return;
    }
  }
  cout << (a + b) / (2. * ((a + b) / (2 * b)));
}
int main() {
  fast();
  long long t = 1;
  while (t--) {
    solve();
  }
}
