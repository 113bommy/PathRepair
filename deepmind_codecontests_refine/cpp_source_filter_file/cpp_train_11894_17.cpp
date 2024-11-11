#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5 + 5;
const int MAX_L = 20;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;
void solve() {
  int n;
  cin >> n;
  if (n < 4)
    cout << "-1\n";
  else {
    if (n % 2) {
      for (int i = n; i > 0; i -= 2) cout << i << " ";
      cout << "4 2 ";
      for (int i = 6; i < n; i++) cout << i << " ";
      cout << "\n";
    } else {
      for (int i = n - 1; i > 0; i -= 2) cout << i << " ";
      cout << "4 2 ";
      for (int i = 6; i < n; i++) cout << i << " ";
      cout << "\n";
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc;
  cin >> tc;
  for (int t = 1; t <= tc; t++) {
    solve();
  }
}
