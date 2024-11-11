#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long k;
  cin >> k;
  if (k > 36) {
    cout << -1;
  } else if (k == 1) {
    cout << 6;
  } else {
    while (k >= 2) {
      cout << 8;
      k -= 2;
    }
    if (k == 1) {
      cout << 0;
    }
  }
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  solve();
}
