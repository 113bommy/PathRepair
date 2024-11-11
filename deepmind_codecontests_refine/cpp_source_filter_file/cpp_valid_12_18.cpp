#include <bits/stdc++.h>
using namespace std;
vector<int> g[1000005];
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  int v = (n * m) / 2 - k;
  if (n % 2) {
    k -= m / 2;
    if (k % 2) {
      cout << "NO" << endl;
      return;
    }
  } else if (m % 2) {
    v -= n / 2;
    if (v % 2) {
      cout << "NO" << endl;
      return;
    }
  }
  if ((v % 2) || (k % 2)) {
    cout << "NO" << endl;
    return;
  }
  cout << "YES" << endl;
  return;
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
