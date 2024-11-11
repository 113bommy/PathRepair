#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int x, y;
  cin >> x >> y;
  long long int temp = x;
  long long int ans = 0;
  if (x == 1 && y > 1) {
    cout << "NO" << endl;
    return;
  }
  if (x == y) {
    cout << "YES" << endl;
    return;
  }
  if (temp % 2 != 0) {
    --temp;
    ans = (temp * 3) / 2;
    if (ans == x) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  } else {
    ans = (x * 3) / 2;
    if (ans == y) {
      cout << "YES" << endl;
      return;
    }
    --ans;
    if (ans == x) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
