#include <bits/stdc++.h>
using namespace std;
const double pi = 3.141592653;
const long long infi = 1000000001;
const long long MOD = 1000000007;
const long long mod = 998244353;
const string no = "NO\n", yes = "YES\n";
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  long long n, m, i, length, d, bank, k, j, x, y, ans, q;
  string s;
  while (t--) {
    ans = 0;
    cin >> s;
    set<char> st{'a', 'e', 'i', 'o', 'u', '0', '2', '4', '6', '8'};
    for (auto j : s) {
      if (st.find(j) != st.end()) ans++;
    }
    cout << ans << endl;
  }
  return 0;
}
