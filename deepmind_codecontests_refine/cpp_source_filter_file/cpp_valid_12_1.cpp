#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n, m, k;
  cin >> n >> m >> k;
  long long int a = m / 2;
  if (k > n * a) {
    cout << "NO " << endl;
    return;
  }
  if (k == 0) {
    if (n % 2 == 0) {
      cout << "YES" << endl;
      return;
    } else {
      cout << "NO" << endl;
      return;
    }
  }
  if (n % 2 == 0) {
    if (k % 2 == 0) {
      cout << "YES" << endl;
      return;
    } else {
      cout << "NO " << endl;
      return;
    }
  } else {
    if (k > m / 2) {
      k = k - m / 2;
      n--;
      if (k % 2 == 0) {
        cout << "YES" << endl;
        return;
      } else {
        cout << "NO " << endl;
        return;
      }
    } else {
      cout << "NO " << endl;
      return;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  while (t--) solve();
}
