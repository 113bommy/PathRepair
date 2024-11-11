#include <bits/stdc++.h>
using namespace std;
long long int dp[1000001];
long long int dp1[1000001];
long long int inv[1000001];
void solve() {
  int n;
  cin >> n;
  string a, b;
  cin >> a >> b;
  for (int i = 0; i < n; i++) {
    if (a[i] == '1' || b[i] == '1') {
      cout << "NO";
      return;
    }
  }
  cout << "YES";
}
void read_input() {}
void case_number() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    solve();
    cout << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  case_number();
  return 0;
}
