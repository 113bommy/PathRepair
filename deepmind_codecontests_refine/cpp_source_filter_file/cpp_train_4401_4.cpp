#include <bits/stdc++.h>
using namespace std;
const long long int mxN = 2e5 + 5;
long long int dp[205][205][205];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long int t, i, j, m, n, pos, y, x, k, weigh, ans, sum, maxi, mini;
  ;
  string s;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<long long int> v(n);
    for (auto &z : v) cin >> z;
    set<long long int> st(v.begin(), v.end());
    cout << (st.size() == 1 ? 1 : n) << "\n";
  }
}
