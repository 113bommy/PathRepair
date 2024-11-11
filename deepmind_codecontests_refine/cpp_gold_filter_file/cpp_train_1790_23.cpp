#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  if (n == 2) {
    cout << "2" << endl;
    return;
  }
  if (n % 2 == 1) {
    cout << "1" << endl;
    return;
  } else {
    cout << "0" << endl;
    return;
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
