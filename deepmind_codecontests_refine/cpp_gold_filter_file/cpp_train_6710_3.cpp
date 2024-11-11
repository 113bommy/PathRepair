#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 2e6 + 10, inf = 1e18, mod = 1e9 + 7;
long long n;
string s, t = "aeouyi";
void Read_input() { cin >> n >> s; }
void Solve() {
  long long ans = 0;
  for (long long i = 0; i < n; i++) {
    if (s[i] == '1')
      ans++;
    else {
      ans++;
      break;
    }
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  Read_input(), Solve();
  return 0;
}
