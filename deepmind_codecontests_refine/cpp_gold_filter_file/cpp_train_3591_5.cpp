#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n, m;
  cin >> n >> m;
  if (n == 1) {
    cout << 1;
    exit(0);
  }
  if (m - 1 < n - m)
    cout << m + 1;
  else
    cout << m - 1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int TESTS = 1;
  while (TESTS--) {
    solve();
  }
  return 0;
}
