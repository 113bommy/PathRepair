#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m;
  cin >> n >> m;
  int min = INT_MAX, max = INT_MIN;
  if (n == 0 && m != 0) {
    cout << "Impossible";
    return;
  } else {
    max = m <= 1 ? n : n + (m - 1);
    min = m <= n ? n : m;
  }
  cout << min << ' ' << max;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc;
  tc = 1;
  while (tc--) {
    solve();
  }
}
