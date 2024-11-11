#include <bits/stdc++.h>
const long long inf = 1e18;
const int32_t M = 1e9 + 7;
const int32_t mxn = 1e6 + 1;
using namespace std;
template <typename T>
istream& operator>>(istream& in, vector<T>& a) {
  for (auto& i : a) in >> i;
  return in;
}
template <typename T>
ostream& operator<<(ostream& out, vector<T>& a) {
  for (auto& i : a) out << i << "";
  return out;
}
void solve() {
  long long n;
  cin >> n;
  string s;
  cin >> s;
  long long i;
  for (i = 1; i <= n * 9; ++i) {
    long long c = 0;
    long long it = 0;
    for (auto ch : s) {
      c += ch - '0';
      if (c == i) {
        it++;
        c = 0;
      }
    }
    if (c == 0 && it > 1) {
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) solve();
  return 0;
}
