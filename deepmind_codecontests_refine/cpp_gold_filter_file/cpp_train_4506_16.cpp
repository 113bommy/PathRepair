#include <bits/stdc++.h>
using namespace std;
void init() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
void solve() {
  int t;
  cin >> t;
  while (t--) {
    long long int a, b, c;
    cin >> a >> b >> c;
    long long int d = max(a, max(b, c));
    d = d + 1;
    cout << d << "\n";
  }
}
int main() {
  init();
  solve();
}
