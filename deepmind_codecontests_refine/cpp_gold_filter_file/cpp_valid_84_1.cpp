#include <bits/stdc++.h>
using namespace std;
void solve() {
  double n, s;
  cin >> n >> s;
  cout << (int)(floor(s / floor(n / 2 + 1))) << '\n';
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
