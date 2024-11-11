#include <bits/stdc++.h>
using namespace std;
void fileioe() {
  freopen("input.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  freopen("error.txt", "w", stderr);
}
const long long mod = 1000000007;
const long long INF = 1e18;
const long long MAX = 100001;
void solve() {
  long long n;
  cin >> n;
  if (n <= 3)
    cout << -1 << endl;
  else {
    if (n & 1) {
      for (int i = 1; i <= n; i++) {
        if (i % 2 != 0) cout << i << " ";
      }
      cout << n - 3 << " " << n - 1 << " ";
      for (int i = n - 4; i >= 1; i--) {
        if (i % 2 == 0) cout << i << " ";
      }
      cout << endl;
    } else if (n % 2 == 0) {
      for (int i = 1; i <= n; i++) {
        if (i % 2 == 0) cout << i << " ";
      }
      cout << n - 3 << " " << n - 1 << " ";
      for (int i = n - 4; i >= 1; i--) {
        if (i & 1) cout << i << " ";
      }
      cout << endl;
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t;
  t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
